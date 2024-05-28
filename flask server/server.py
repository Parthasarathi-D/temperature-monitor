from flask import Flask, request, jsonify
import requests

app = Flask(__name__)

@app.route('/receive_data', methods=['POST'])
def receive_data():
    data = request.get_json()
    if not data:
        return jsonify({"message": "No data received"}), 400
    
    temperature = data.get('temperature', 'default_temperature')
    latitude = data.get('latitude', 'default_latitude')
    longitude = data.get('longitude', 'default_longitude')
    
    # Forward data to AWS Lambda (if needed)
    lambda_url = 'https://fdawv65mwd.execute-api.eu-north-1.amazonaws.com/default/sensortos3'
    lambda_data = {
        'temperature': temperature,
        'latitude': latitude,
        'longitude': longitude
    }
    response = requests.post(lambda_url, json=lambda_data)
    
    return jsonify({"message": "Data received and forwarded", "lambda_response": response.text})

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
