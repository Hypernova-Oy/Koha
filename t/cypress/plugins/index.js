const { startDevServer } = require("@cypress/webpack-dev-server");
const webpackConfig = require("@vue/cli-service/webpack.config.js");

module.exports = (on, config) => {
    on("dev-server:start", options =>
        startDevServer({
            options,
            webpackConfig,
        })
    );

    return config;
};

const mysql = require("cypress-mysql");

module.exports = (on, config) => {
    mysql.configurePlugin(on);
};

const { buildSamplePatron } = require("./mockData.js");

module.exports = (on, config) => {
    on("task", {
        buildSamplePatron,
    });
    return config;
};
