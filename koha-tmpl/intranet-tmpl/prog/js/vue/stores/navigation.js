import { defineStore } from "pinia";
import { reactive, toRefs, computed } from "vue";

export const useNavigationStore = defineStore("navigation", () => {
    const store = reactive({
        routeState: {
            alt: "Home",
            href: "/cgi-bin/koha/mainpage.pl",
            is_navigation_item: false,
            is_base: true,
            children: [],
        },
        current: null,
        params: {},
        query: {},
    });
    const actions = {
        setRoutes(routesDef) {
            if (!Array.isArray(routesDef)) {
                routesDef = [routesDef];
            }
            this.routeState.children = routesDef;
            _traverseChildren(this.routeState);

            return this.navigationRoutes;

            // Function declarations

            function _traverseChildren(parent) {
                if (isParent(parent)) {
                    parent.children.forEach(child => {
                        _setChildDefaults(parent, child);
                        _traverseChildren(child);
                    });
                }
            }

            function _setChildDefaults(parent, child) {
                child.parent = parent;
                if (isRoutable(child)) {
                    _setMetadata(child);
                }
                if (parent.children.length === 1 && parent.is_base) {
                    _setBaseAndNavigationDefaults(child, {
                        is_base: true,
                        is_navigation_item: false,
                    });
                } else {
                    _setBaseAndNavigationDefaults(child, {
                        is_base: false,
                        is_navigation_item: true,
                    });
                }
            }

            function _setBaseAndNavigationDefaults(
                child,
                { is_base, is_navigation_item }
            ) {
                child.is_base =
                    child.is_base !== undefined ? child.is_base : is_base;
                child.is_navigation_item =
                    child.is_navigation_item !== undefined
                        ? child.is_navigation_item
                        : is_navigation_item;
            }

            function _setMetadata(child) {
                if (!child.meta) child.meta = {};
                child.meta.self = child;
            }
        },
    };

    const getters = {
        breadcrumbs: computed(() => {
            if (store.current)
                return _buildFromCurrentMatches(
                    store.current,
                    store.routeState,
                    store.params
                );

            return _getBaseElements(store.routeState);

            // Function declarations

            function _getBaseElements(parent) {
                if (!parent.is_base) return [];
                let next = {};
                if (isParent(parent)) {
                    next = _defineNextElement(parent);
                }
                return [
                    {
                        ...parent,
                        children: null,
                    },
                    ..._getBaseElements(next),
                ];
            }

            function _defineNextElement(parent) {
                return (
                    parent.children.find(child => child.is_default) ||
                    parent.children[0]
                );
            }

            function _buildFromCurrentMatches(
                currentMatches,
                routeState,
                params
            ) {
                return [
                    {
                        ...routeState,
                        icon: null,
                        children: null,
                    },
                    ..._mapMatches(currentMatches, params),
                ];
            }

            function _isBaseOrNotStub(child) {
                return child.is_base || (child.path && child.path !== "");
            }

            function _isEmptyNode(child) {
                return !child.is_empty;
            }

            function _getPath(match, params) {
                if (!match.name && match.path && params) {
                    return match.path.replaceAll(/(:[^/]+)/g, param_name => {
                        return params[param_name.substr(1)];
                    });
                }
                return match.path;
            }

            function _mapMatches(currentMatches, params) {
                const matches = currentMatches
                    .filter(match => _isBaseOrNotStub(match.meta.self))
                    .filter(match => _isEmptyNode(match.meta.self))
                    .map(match => {
                        let path = _getPath(match, params);
                        const externalPath = path.includes(".pl");
                        let {
                            meta: { self },
                        } = match;
                        if (self.breadcrumbFormat) {
                            self = self.breadcrumbFormat({
                                match: self,
                                params: store.params,
                                query: store.query,
                            });
                        }
                        const breadcrumbInfo = {
                            ...match.meta.self,
                            icon: null,
                            ...(externalPath
                                ? { href: path, path: null }
                                : { path }),
                            children: null,
                        };
                        return breadcrumbInfo;
                    });
                return matches;
            }
        }),
        leftNavigation: computed(() => {
            const currentRoute = store.current[store.current.length - 1];
            if (currentRoute) {
                const alternateMenuRequired =
                    currentRoute.meta.self.alternateLeftMenu;
                if (alternateMenuRequired) return alternateMenuRequired;
            }
            return _getNavigationElements(store.routeState);

            // Function declarations

            function _getNavigationElements(parent, prevPath = "") {
                if (_isBaseAndNoChildren(parent)) return [];
                if (parent.is_base)
                    return _buildChildNavigationElements(parent).flat(Infinity);

                const builtPath = _buildPath(prevPath, parent);

                let children = [];
                if (!parent.is_end_node && isParent(parent)) {
                    children = _buildChildNavigationElements(parent, builtPath);
                }

                return {
                    ...parent,
                    path: builtPath ? builtPath : parent.path,
                    children,
                };
            }

            function _buildPath(prevPath, element) {
                let builtPath;

                if (isRoutable(element) && isAbsolutePath(element.path)) {
                    builtPath = element.path;
                } else {
                    if (prevPath)
                        builtPath =
                            "" + prevPath + addSlashIfNotPresent(prevPath);
                    if (isRoutable(element))
                        builtPath = "" + builtPath + element.path;
                }

                return builtPath;
            }

            function _buildChildNavigationElements(parent, builtPath) {
                return parent.children
                    .filter(child => child.is_base || child.is_navigation_item)
                    .map(child => _getNavigationElements(child, builtPath));
            }

            function _isBaseAndNoChildren(parent) {
                return (
                    parent.is_base &&
                    (!parent.children || !parent.children.length)
                );
            }
        }),
        navigationRoutes: computed(() => {
            let routes = _toRoute(store.routeState);
            return Array.isArray(routes) ? routes : [routes];

            // Function declarations

            function _toRoute(parent) {
                if (!isRoutable(parent)) return _getRoutableChildren(parent);
                return parent;
            }

            function _getRoutableChildren(parent) {
                return parent.children
                    .map(child => _toRoute(child))
                    .flat(Infinity);
            }
        }),
    };

    return {
        ...toRefs(store),
        ...actions,
        ...getters,
    };
});

function addSlashIfNotPresent(path) {
    return /\/$/.test(path) ? "" : "/";
}

function isRoutable(element) {
    return element.path !== undefined || element.name !== undefined;
}

function isParent(parent) {
    return parent.children && parent.children.length;
}

function isAbsolutePath(path) {
    return /^\//.test(path);
}
