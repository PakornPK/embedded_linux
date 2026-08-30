#include <iostream>
#include <memory>
#include <httplib.h>
#include <nlohmann/json.hpp>
#include "mock_server.hpp"

using namespace std;
using namespace httplib;
using namespace nlohmann;

int main(void) {
    unique_ptr<ISensor> sensor = make_unique<MockTemperatureSensor>();

    if (!sensor->initialize()) {
        cerr << "Failed to initialize hardware sensor!" << endl;
        return 1;
    }

    Server svr;

    svr.Get("/api/v1/telemetry", [&](const Request&, Response& res) {
            float temp = sensor->read_temperature();

            json response_data = {
                {"status", "ok"},
                {"device_id", "edge-node-01"},
                {"telemetry" , {
                    {"temperature_celsius", temp},
                    {"unit", "C"}
                }}
                };

            res.set_content(response_data.dump(4), "application/json");
     });

    cout << "Starting Edge Deamon on http://0.0.0.0:8080 ..." << endl;
    svr.listen("0.0.0.0", 8080);

    return 0;
}
