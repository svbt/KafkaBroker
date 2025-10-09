#include <cppkafka/cppkafka.h>
#include <nlohmann/json.hpp>
#include <iostream>

using namespace cppkafka;
using json = nlohmann::json;

int main() 
{
    Configuration config = {
        { "metadata.broker.list", "kafka1:19092,kafka2:19093" },
        { "group.id", "reminder-consumer" },
        { "auto.offset.reset", "earliest" }
    };

    Consumer consumer(config);
    consumer.subscribe({ "reminders" });

    std::cout << "📡 Consumer started..." << std::endl;

    while (true) 
    {
        Message msg = consumer.poll();
        if (msg) 
        {
            if (msg.get_error()) 
            {
                std::cerr << "⚠️ Error: " << msg.get_error() << std::endl;
                continue;
            }
            try 
            {
                auto j = json::parse(msg.get_payload());
                std::cout << "📥 Received: " << j.dump() << std::endl;
            } 
            catch (const std::exception& e) 
            {
                std::cerr << "JSON parse error: " << e.what() << std::endl;
            }
        }
    }
}

