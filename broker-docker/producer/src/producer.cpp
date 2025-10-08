#include <cppkafka/cppkafka.h>
#include <nlohmann/json.hpp>
#include <iostream>
#include <thread>
#include <chrono>

using namespace cppkafka;
using json = nlohmann::json;

int main() 
{
    // Use the internal listener ports
    Configuration config = {
        { "metadata.broker.list", "kafka1:19092,kafka2:19093" }
    };

    Producer producer(config);
    std::string topic = "reminders";
    int id = 1;

    std::cout << "🚀 Producer started..." << std::endl;

    while (true) 
    {
        json payload = {
            {"id", id++},
            {"title", "Test Reminder"},
            {"timestamp", "2025-10-04T20:00:00Z"}
        };
	
    	std::string serialized = payload.dump();
    	producer.produce(MessageBuilder(topic).payload(serialized));
        producer.flush();
        std::cout << "✅ Produced: " << payload.dump() << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
}

