# KafkaBroker
Kafka broker

# Start Kafka:
docker-compose up -d

# Check if containers are running:
docker ps

You should see zookeeper and broker.

# Test Kafka is working
docker exec -it broker bash

# Create a topic
kafka-topics --create \
  --topic test-topic \
  --bootstrap-server localhost:9092 \
  --partitions 1 --replication-factor 1

# Produde a message
kafka-console-producer --topic test-topic --bootstrap-server localhost:9092 > Hello Kafka!

# Consume the message
Open another terminal:

docker exec -it broker kafka-console-consumer \
  --topic test-topic \
  --from-beginning \
  --bootstrap-server localhost:9092

You should see
Hello Kafka!

