<template>
    <div v-if="!initialized">{{ $__("Loading") }}</div>
    <div v-else id="agreements_show">
        <Toolbar>
            <ToolbarButton
                :to="{
                    name: 'AgreementsFormAddEdit',
                    params: { agreement_id: agreement.agreement_id },
                }"
                icon="pencil"
                :title="$__('Edit')"
            />
            <a
                @click="
                    delete_agreement(agreement.agreement_id, agreement.name)
                "
                class="btn btn-default"
                ><font-awesome-icon icon="trash" /> {{ $__("Delete") }}</a
            >
        </Toolbar>

        <h2>
            {{ $__("Agreement #%s").format(agreement.agreement_id) }}
        </h2>
        <div>
            <fieldset class="rows">
                <ol>
                    <li>
                        <label>{{ $__("Agreement name") }}:</label>
                        <span>
                            {{ agreement.name }}
                        </span>
                    </li>
                    <li>
                        <label>{{ $__("Vendor") }}:</label>
                        <span v-if="agreement.vendor_id">
                            <a
                                :href="`/cgi-bin/koha/acqui/booksellers.pl?booksellerid=${agreement.vendor_id}`"
                            >
                                {{ agreement.vendor.name }}
                            </a>
                        </span>
                    </li>
                    <li>
                        <label>{{ $__("Description") }}:</label>
                        <span>
                            {{ agreement.description }}
                        </span>
                    </li>
                    <li>
                        <label>{{ $__("Status") }}:</label>
                        <span>{{
                            get_lib_from_av(
                                "av_agreement_statuses",
                                agreement.status
                            )
                        }}</span>
                    </li>
                    <li>
                        <label>{{ $__("Closure reason") }}:</label>
                        <span>{{
                            get_lib_from_av(
                                "av_agreement_closure_reasons",
                                agreement.closure_reason
                            )
                        }}</span>
                    </li>
                    <li>
                        <label>{{ $__("Is perpetual") }}:</label>
                        <span v-if="agreement.is_perpetual">{{
                            $__("Yes")
                        }}</span>
                        <span v-else>{{ $__("No") }}</span>
                    </li>
                    <li>
                        <label>{{ $__("Renewal priority") }}:</label>
                        <span>{{
                            get_lib_from_av(
                                "av_agreement_renewal_priorities",
                                agreement.renewal_priority
                            )
                        }}</span>
                    </li>
                    <li>
                        <label>{{ $__("License info") }}:</label>
                        <span>{{ agreement.license_info }}</span>
                    </li>

                    <li v-if="agreement.periods.length">
                        <label>{{ $__("Periods") }}</label>
                        <table>
                            <thead>
                                <th>{{ $__("Period start") }}</th>
                                <th>{{ $__("Period end") }}</th>
                                <th>{{ $__("Cancellation deadline") }}</th>
                                <th>{{ $__("Period note") }}</th>
                            </thead>
                            <tbody>
                                <tr
                                    v-for="(
                                        period, counter
                                    ) in agreement.periods"
                                    v-bind:key="counter"
                                >
                                    <td>
                                        {{ format_date(period.started_on) }}
                                    </td>
                                    <td>{{ format_date(period.ended_on) }}</td>
                                    <td>
                                        {{
                                            format_date(
                                                period.cancellation_deadline
                                            )
                                        }}
                                    </td>
                                    <td>{{ period.notes }}</td>
                                </tr>
                            </tbody>
                        </table>
                    </li>

                    <li v-if="agreement.user_roles.length">
                        <label>{{ $__("Users") }}</label>
                        <table>
                            <thead>
                                <th>{{ $__("Name") }}</th>
                                <th>{{ $__("Role") }}</th>
                            </thead>
                            <tbody>
                                <tr
                                    v-for="(
                                        role, counter
                                    ) in agreement.user_roles"
                                    v-bind:key="counter"
                                >
                                    <td>{{ patron_to_html(role.patron) }}</td>
                                    <td>
                                        {{
                                            get_lib_from_av(
                                                "av_user_roles",
                                                role.role
                                            )
                                        }}
                                    </td>
                                </tr>
                            </tbody>
                        </table>
                    </li>

                    <li v-if="agreement.agreement_licenses.length">
                        <label>{{ $__("Licenses") }}</label>
                        <table>
                            <thead>
                                <th>{{ $__("Name") }}</th>
                                <th>{{ $__("Status") }}</th>
                                <th>{{ $__("Physical location") }}</th>
                                <th>{{ $__("Notes") }}</th>
                                <th>{{ $__("URI") }}</th>
                            </thead>
                            <tbody>
                                <tr
                                    v-for="(
                                        agreement_license, counter
                                    ) in agreement.agreement_licenses"
                                    v-bind:key="counter"
                                >
                                    <td>
                                        <router-link
                                            :to="{
                                                name: 'LicensesShow',
                                                params: {
                                                    license_id:
                                                        agreement_license.license_id,
                                                },
                                            }"
                                        >
                                            {{ agreement_license.license.name }}
                                        </router-link>
                                    </td>
                                    <td>
                                        {{
                                            get_lib_from_av(
                                                "av_agreement_license_statuses",
                                                agreement_license.status
                                            )
                                        }}
                                    </td>
                                    <td>
                                        {{
                                            get_lib_from_av(
                                                "av_agreement_license_location",
                                                agreement_license.physical_location
                                            )
                                        }}
                                    </td>
                                    <td>{{ agreement_license.notes }}</td>
                                    <td>{{ agreement_license.uri }}</td>
                                </tr>
                            </tbody>
                        </table>
                    </li>

                    <li v-if="agreement.agreement_relationships.length">
                        <label>{{ $__("Related agreements") }}</label>
                        <div id="agreement_relationships">
                            <div
                                v-for="relationship in agreement.agreement_relationships"
                                v-bind:key="relationship.related_agreement_id"
                            >
                                <span
                                    ><router-link
                                        :to="{
                                            name: 'AgreementsShow',
                                            params: {
                                                agreement_id:
                                                    relationship
                                                        .related_agreement
                                                        .agreement_id,
                                            },
                                        }"
                                        >{{
                                            relationship.related_agreement.name
                                        }}</router-link
                                    ></span
                                >
                                {{
                                    get_lib_from_av(
                                        "av_agreement_relationships",
                                        relationship.relationship
                                    )
                                }}
                                {{ agreement.name }}
                            </div>
                        </div>
                    </li>

                    <li v-if="agreement.agreement_packages.length">
                        <label>{{ $__("Packages") }}</label>
                        <div id="agreement_packages">
                            <div
                                v-for="agreement_package in agreement.agreement_packages"
                                v-bind:key="agreement_package.package_id"
                            >
                                <span
                                    v-if="
                                        agreement_package.package.external_id &&
                                        agreement_package.package.provider ==
                                            'ebsco'
                                    "
                                >
                                    <router-link
                                        :to="{
                                            name: 'EHoldingsEBSCOPackagesShow',
                                            params: {
                                                package_id:
                                                    agreement_package.package
                                                        .external_id,
                                            },
                                        }"
                                        >{{
                                            agreement_package.package.name
                                        }}</router-link
                                    >
                                    {{ $__("(EBSCO)") }}</span
                                >
                                <span v-else
                                    ><router-link
                                        :to="{
                                            name: 'EHoldingsLocalPackagesShow',
                                            params: {
                                                package_id:
                                                    agreement_package.package
                                                        .package_id,
                                            },
                                        }"
                                        >{{
                                            agreement_package.package.name
                                        }}</router-link
                                    >
                                    ({{ $__("local") }})</span
                                >
                            </div>
                        </div>
                    </li>

                    <li v-if="agreement.documents.length">
                        <label>{{ $__("Documents") }}</label>
                        <div id="agreement_documents">
                            <ul>
                                <li
                                    v-for="document in agreement.documents"
                                    v-bind:key="document.document_id"
                                >
                                    <div v-if="document.file_name">
                                        <span v-if="document.file_description"
                                            >{{ document.file_description }} -
                                        </span>
                                        <a
                                            download
                                            :href="`/api/v1/erm/documents/${document.document_id}/file/content`"
                                        >
                                            {{ document.file_name }}
                                            <i class="fa fa-download"></i>
                                        </a>
                                        ({{ document.file_type }})
                                        {{ $__("Uploaded on") }}:
                                        {{ format_date(document.uploaded_on) }}
                                    </div>
                                    <div v-if="document.physical_location">
                                        {{ $__("Physical location") }}:
                                        {{ document.physical_location }}
                                    </div>
                                    <div v-if="document.uri">
                                        {{ $__("URI") }}: {{ document.uri }}
                                    </div>
                                    <div v-if="document.notes">
                                        {{ $__("Notes") }}: {{ document.notes }}
                                    </div>
                                </li>
                            </ul>
                        </div>
                    </li>
                </ol>
            </fieldset>
            <AdditionalFieldsDisplay
                resource_type="agreement"
                :additional_field_values="
                    agreement._strings.additional_field_values
                "
            />
            <fieldset class="action">
                <router-link
                    :to="{ name: 'AgreementsList' }"
                    role="button"
                    class="cancel"
                    >{{ $__("Close") }}</router-link
                >
            </fieldset>
        </div>
    </div>
</template>

<script>
import { inject } from "vue";
import { APIClient } from "../../fetch/api-client.js";
import Toolbar from "../Toolbar.vue";
import ToolbarButton from "../ToolbarButton.vue";
import AdditionalFieldsDisplay from "../AdditionalFieldsDisplay.vue";

export default {
    setup() {
        const format_date = $date;
        const patron_to_html = $patron_to_html;

        const { setConfirmationDialog, setMessage } = inject("mainStore");

        const ERMStore = inject("ERMStore");
        const { get_lib_from_av } = ERMStore;

        return {
            format_date,
            patron_to_html,
            get_lib_from_av,
            setConfirmationDialog,
            setMessage,
        };
    },
    data() {
        return {
            agreement: {
                agreement_id: null,
                name: "",
                vendor_id: null,
                vendor: null,
                description: "",
                status: "",
                closure_reason: "",
                is_perpetual: false,
                renewal_priority: "",
                license_info: "",
                periods: [],
                user_roles: [],
                extended_attributes: [],
                _strings: [],
                agreement_packages: [],
            },
            initialized: false,
        };
    },
    beforeRouteEnter(to, from, next) {
        next(vm => {
            vm.getAgreement(to.params.agreement_id);
        });
    },
    beforeRouteUpdate(to, from) {
        this.agreement = this.getAgreement(to.params.agreement_id);
    },
    methods: {
        async getAgreement(agreement_id) {
            const client = APIClient.erm;
            client.agreements.get(agreement_id).then(
                agreement => {
                    this.agreement = agreement;
                    this.initialized = true;
                },
                error => {}
            );
        },
        delete_agreement: function (agreement_id, agreement_name) {
            this.setConfirmationDialog(
                {
                    title: this.$__(
                        "Are you sure you want to remove this agreement?"
                    ),
                    message: agreement_name,
                    accept_label: this.$__("Yes, delete"),
                    cancel_label: this.$__("No, do not delete"),
                },
                () => {
                    const client = APIClient.erm;
                    client.agreements.delete(agreement_id).then(
                        success => {
                            this.setMessage(
                                this.$__("Agreement %s deleted").format(
                                    agreement_name
                                ),
                                true
                            );
                            this.$router.push({ name: "AgreementsList" });
                        },
                        error => {}
                    );
                }
            );
        },
    },
    components: { Toolbar, ToolbarButton, AdditionalFieldsDisplay },
    name: "AgreementsShow",
};
</script>
<style scoped>
#agreement_documents ul {
    padding-left: 0px;
}
</style>
