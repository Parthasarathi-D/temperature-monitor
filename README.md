# temperature-monitor

## Abstract
### This project involves the development of a real-time data processing system for IoT devices using AWS services. The primary objective is to collect, process, and store data from a temperature sensor and a GPS module connected to a NodeMCU. The system uses a Python server to receive data from the NodeMCU and forward it to an AWS Lambda function, which processes the data and stores it in an Amazon S3 bucket. This setup provides a scalable and reliable solution for real-time data monitoring and storage. The project demonstrates successful integration between IoT hardware and cloud services, ensuring efficient data handling and storage. Future work could enhance the system by incorporating additional sensors and improving data visualization techniques.


## Introduction
### Background Information
#### The Internet of Things (IoT) has revolutionized the way we interact with our environment by enabling everyday objects to collect, exchange, and process data. IoT devices, such as sensors and actuators, are widely used in various domains, including smart homes, industrial automation, environmental monitoring, and healthcare. These devices generate massive amounts of data that need to be collected, processed, and analyzed in real-time to extract meaningful insights and make informed decisions.
#### Real-time data processing is crucial in IoT applications, as it allows for immediate responses to changes in the environment. For instance, in a smart home setup, real-time data from temperature sensors can help maintain optimal indoor conditions by adjusting the heating or cooling systems. Similarly, in industrial settings, real-time monitoring of machinery can prevent breakdowns and improve efficiency.

## Objectives of the Project
### The primary objective of this project is to design and implement a real-time data processing system for IoT devices using AWS services. The specific goals include:
#### 1.	Data Collection: Set up a NodeMCU microcontroller with a temperature sensor and a GPS module to collect environmental data.
#### 2.	Data Transmission: Implement a Python server to receive data from the NodeMCU and forward it to an AWS Lambda function.
#### 3.	Data Processing and Storage: Use AWS Lambda to process the received data and store it in an Amazon S3 bucket for later retrieval and analysis.
#### 4.	Real-time Feedback: Ensure that the system can handle real-time data transmission and processing, providing immediate feedback and data storage.
#### 5.	Scalability and Reliability: Leverage the scalability and reliability of AWS services to handle large volumes of data and ensure continuous operation.


## Importance and Relevance of the Project
### The project is significant for several reasons:
#### 1.	Real-time Monitoring: By enabling real-time data processing, the system can provide immediate insights and responses, which are critical in applications such as environmental monitoring, smart cities, and industrial automation.
#### 2.	Scalability: Using AWS services like Lambda and S3 ensures that the system can scale to handle increasing amounts of data without compromising performance. This is particularly important as the number of IoT devices continues to grow.
#### 3.	Reliability: AWS offers highly reliable and durable storage solutions, ensuring that the collected data is securely stored and accessible whenever needed. This reliability is crucial for long-term data analysis and decision-making.
#### 4.	Cost-effectiveness: By utilizing serverless computing (AWS Lambda), the project reduces the need for managing dedicated servers, leading to cost savings and easier maintenance.
#### 5.	Versatility: The framework developed in this project can be adapted to various other IoT applications, making it a versatile solution for different real-time data processing needs.


## Materials and Methods
### Description of Hardware Components
#### 1.	Temperature Sensor (DHT22)
•	Description: The DHT22 is a digital temperature and humidity sensor. It uses a capacitive humidity sensor and a thermistor to measure the surrounding air and outputs a digital signal on the data pin (no analog input pins needed).
•	Specifications:
•	Temperature Range: -40 to 80°C
•	Accuracy: ±0.5°C
•	Operating Voltage: 3.3V to 5V
•	Humidity Range: 0-100%
•	Interface: Single-wire digital interface
#### 2.	GPS Module (Neo-6M)
•	Description: The Neo-6M GPS module is a satellite navigation receiver used for obtaining the geographical location (latitude and longitude) of the device.
•	Specifications:
•	Position Accuracy: 2.5m
•	Velocity Accuracy: 0.1 m/s
•	Operating Voltage: 2.7V to 3.6V
•	Interface: UART
#### 3.	NodeMCU (ESP8266)
•	Description: NodeMCU is an open-source IoT platform. It includes firmware that runs on the ESP8266 Wi-Fi SoC from Espressif Systems and hardware based on the ESP-12 module. It provides Wi-Fi connectivity and is programmable via the Arduino IDE.
•	Specifications:
•	Microcontroller: ESP8266
•	Operating Voltage: 3.3V
•	Digital I/O Pins: 11
•	Flash Memory: 4MB


### Description of Software Components
#### 1.	AWS Lambda
•	Description: AWS Lambda is a serverless compute service that allows you to run code without provisioning or managing servers. You pay only for the compute time you consume.
•	Purpose: Used for processing incoming data from the IoT device and storing it in Amazon S3.
#### 2.	Amazon S3 (Simple Storage Service)
•	Description: Amazon S3 is an object storage service that offers industry-leading scalability, data availability, security, and performance.
•	Purpose: Used for storing the processed data from the IoT devices in a scalable and durable manner.
#### 3.	AWS API Gateway
•	Description: AWS API Gateway is a managed service that allows developers to create, publish, maintain, monitor, and secure APIs at any scale.
•	Purpose: Provides a RESTful endpoint for the NodeMCU to send data to AWS Lambda.
#### 4.	Python Scripts
•	Description: Scripts written in Python to handle data received from the IoT devices and trigger the AWS Lambda function.
•	Purpose: Acts as a bridge between the NodeMCU and AWS Lambda, ensuring data is correctly formatted and transmitted.
#### 5.	Flask (Python Web Framework)
•	Description: Flask is a lightweight WSGI web application framework in Python.
•	Purpose: Used to create a simple server to receive HTTP POST requests from the NodeMCU and forward the data to AWS Lambda.

## Implementation
### Detailed Description of the Implementation Process
#### The implementation of the real-time data processing system for IoT devices involves several steps, from setting up hardware components to configuring AWS services. Below is a detailed breakdown of the implementation process:
1.	Hardware Setup and Configuration
2.	NodeMCU Programming
3.	Python Flask Server Setup
4.	AWS Lambda Function Setup
5.	AWS S3 Configuration
6.	Testing and Debugging
#### Hardware Setup and Configuration
1.	Connecting the DHT22 Temperature Sensor:
•	Connect the VCC pin of the DHT22 sensor to the 3.3V pin on the NodeMCU.
•	Connect the GND pin of the DHT22 sensor to the GND pin on the NodeMCU.
•	Connect the data pin of the DHT22 sensor to the D4 pin on the NodeMCU.
#### 2.	Connecting the Neo-6M GPS Module:
•	Connect the VCC pin of the GPS module to the 3.3V pin on the NodeMCU.
•	Connect the GND pin of the GPS module to the GND pin on the NodeMCU.
•	Connect the TX pin of the GPS module to the D1 (RX) pin on the NodeMCU.
•	Connect the RX pin of the GPS module to the D2 (TX) pin on the NodeMCU.
#### NodeMCU Programming
The NodeMCU is programmed using the Arduino IDE to read data from the temperature sensor and the GPS module, and to send this data to a Flask server.

#### Python Flask Server Setup
A Flask server is set up to receive POST requests from the NodeMCU. The server then forwards the data to the AWS Lambda function.


#### AWS Lambda Function Setup
The Lambda function processes the data received from the Flask server and stores it in an S3 bucket.


####  Configuring the Lambda Function:
•	Create a new Lambda function in the AWS Management Console.
•	Copy and paste the Lambda function code.
•	Set up the necessary IAM roles and policies to allow the Lambda function to write to the S3 bucket.
•	Test the Lambda function to ensure it works correctly with sample data.
####  AWS S3 Configuration
##### 1.	Create an S3 Bucket:
•	Go to the AWS S3 console and create a new bucket named allsensordata.
•	Configure the bucket permissions to allow the Lambda function to write data.
##### 2.	Bucket Policy:
{
    "Version": "2012-10-17",
    "Statement": [
        {
            "Effect": "Allow",
            "Principal": "*",
            "Action": "s3:PutObject",
            "Resource": "arn:aws:s3:::allsensordata/*"
        }
    ]
}

## Testing and Debugging
### 1.	Testing the NodeMCU:
•	Upload the NodeMCU code via the Arduino IDE.
•	Open the serial monitor to verify that the NodeMCU is connecting to WiFi and sending data to the Flask server.
### 2.	Testing the Flask Server:
•	Run the Flask server locally.
•	Use a tool like Postman to send a sample POST request to http://<Your_Local_IP>:5000/receive_data and verify that it forwards the data to the Lambda function.
### 3.	Testing the Lambda Function:
•	Test the Lambda function using the AWS console with sample data to ensure it writes data to the S3 bucket correctly.
### 4.	End-to-End Testing:
•	Deploy the NodeMCU, Flask server, and Lambda function.
•	Verify that data flows correctly from the NodeMCU to the S3 bucket through the Flask server and Lambda function.
•	Check the S3 bucket to ensure that files are being created and contain the correct data.


## Analysis of the Data Collected
### Temperature Trends:
#### By analyzing the temperature data collected over a period, trends and patterns can be identified. For example, the temperature might show a gradual increase during the day and a decrease at night.
##### Timestamp                 Temperature (°C)
2023-05-23 12:45:30       23.5
2023-05-23 12:46:30       24.0
2023-05-23 12:47:30       23.8
2023-05-23 12:48:30       24.2
2023-05-23 12:49:30       24.1


### Geolocation Data:
The collected latitude and longitude data can be plotted on a map to visualize the movement of the sensor device. This can be useful for tracking the location of the device in real-time.

## Error Handling and Debugging:
#### During the implementation, several errors were encountered and resolved. For example, initial attempts to send data directly to the AWS Lambda function resulted in permission errors. This was resolved by correctly configuring the IAM roles and policies. Additionally, debugging messages in the serial monitor and Flask server console were crucial for identifying and fixing issues.

## Challenges Faced and How They Were Overcome
### The implementation process presented several challenges, which were addressed as follows:
#### 1.	WiFi Connectivity Issues:
•	Problem: Initial attempts to connect the NodeMCU to WiFi encountered stability issues, causing intermittent disconnections.
•	Solution: Optimized the WiFi connection setup by ensuring proper signal strength and implementing retries in the NodeMCU code to handle disconnections gracefully.
#### 2.	Data Formatting and Parsing Errors:
•	Problem: Incorrectly formatted data or parsing errors in the Flask server and Lambda function led to unsuccessful data storage attempts.
•	Solution: Implemented robust error handling and data validation mechanisms in both the NodeMCU code and server scripts to ensure that the data was correctly formatted before processing.
#### 3.	AWS Lambda and S3 Permissions:
•	Problem: The Lambda function initially faced access issues when trying to write data to the S3 bucket, resulting in access denied errors.
•	Solution: Properly configured IAM roles and bucket policies to grant the necessary permissions for the Lambda function to interact with the S3 bucket.
#### 4.	Testing and Debugging:
•	Problem: Debugging the entire data pipeline from the NodeMCU to AWS was challenging due to the distributed nature of the system.
•	Solution: Used comprehensive logging at each stage of the process (NodeMCU serial monitor, Flask server console, Lambda function logs) to trace and identify issues quickly and accurately.


## Possible Improvements and Future Work
### While the project successfully met its objectives, several areas for improvement and future enhancements were identified:
#### 1.	Enhanced Data Security:
•	Improvement: Implement encryption for data transmission between the NodeMCU, Flask server, and AWS Lambda function to enhance security.
•	Future Work: Implement SSL/TLS for the Flask server and use HTTPS for all data transmissions.
#### 2.	Scalability:
•	Improvement: Optimize the system to handle a larger number of IoT devices simultaneously.
•	Future Work: Use AWS IoT Core to manage multiple IoT devices efficiently and scale the data processing pipeline.
#### 3.	Data Visualization:
•	Improvement: Create a real-time data visualization dashboard to display the collected data.
•	Future Work: Integrate AWS QuickSight or other visualization tools to provide insights and trends from the stored data.
#### 4.	Advanced Data Analytics:
•	Improvement: Implement advanced data analytics to derive meaningful insights from the collected data.
•	Future Work: Use AWS Lambda to trigger data processing workflows and integrate with AWS Machine Learning services for predictive analytics and anomaly detection.
#### 5.	Offline Data Storage:
•	Improvement: Implement offline data storage on the NodeMCU to ensure data collection continues even when the network is unavailable.
•	Future Work: Add local storage capabilities using an SD card module and synchronize data with the server once connectivity is restored.
#### 6.	Integration with Other Sensors:
•	Improvement: Expand the system to include additional sensors such as humidity, air quality, and motion detection.
•	Future Work: Integrate multiple sensors and develop a comprehensive environmental monitoring system.


## Conclusion
### This project aimed to develop a real-time data processing system for IoT devices, leveraging NodeMCU hardware, Python Flask for local data handling, and AWS services for cloud-based data storage and processing. The primary objectives were to collect temperature and geolocation data from a NodeMCU device, transmit this data to a Flask server, forward it to an AWS Lambda function, and store it in an AWS S3 bucket for future retrieval and analysis.

### The system was successfully implemented, with the NodeMCU gathering environmental data and transmitting it over WiFi to the Flask server. The Flask server processed the incoming data and forwarded it to the AWS Lambda function, which then stored the data in an S3 bucket. The project demonstrated the seamless integration of IoT hardware with cloud services, enabling real-time data collection, transmission, storage, and retrieval.

## References
### 1.	Books and Articles:
#### •	Grover, P. (2018). Internet of Things with ESP8266. Packt Publishing.
#### •	Davies, J. (2020). The Internet of Things (MIT Press Essential Knowledge series). MIT Press.
### 2.	Websites:
#### •	AWS Documentation: AWS Lambda Developer Guide
#### •	AWS Documentation: Amazon S3 Developer Guide
#### •	Flask Documentation: Flask - Quickstart
### 3.	Online Tutorials and Blogs:
#### •	"Getting Started with NodeMCU (ESP8266) on Arduino IDE" by Random Nerd Tutorials: Random Nerd Tutorials
#### •	"How to Use AWS Lambda & API Gateway with Python" by Real Python: Real Python
### These references provided valuable information and guidance throughout the project, helping in the successful implementation and understanding of the various components and technologies used.

