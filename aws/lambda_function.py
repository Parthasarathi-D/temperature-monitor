import json
import boto3
import datetime

s3_client = boto3.client('s3')
BUCKET_NAME = 'allsensordata'  # Replace with your bucket name

def lambda_handler(event, context):
    try:
        # Log the event to see its structure
        print("Received event: " + json.dumps(event))
        
        # Check if 'body' is in the event
        if 'body' not in event:
            raise ValueError("'body' not found in event")
        
        body = json.loads(event['body'])
        
        temperature = body.get('temperature', 'default_temperature')
        latitude = body.get('latitude', 'default_latitude')
        longitude = body.get('longitude', 'default_longitude')
        timestamp = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')
        file_name = f"sensor_data/{timestamp.replace(':', '-')}.txt"
        file_content = f"{timestamp},{temperature},{latitude},{longitude}\n"
        
        s3_client.put_object(Bucket=BUCKET_NAME, Key=file_name, Body=file_content, ContentType='text/plain')
        
        return {
            'statusCode': 200,
            'body': json.dumps('Data received and stored in S3')
        }
    except Exception as e:
        # Log the exception details
        print("Error: " + str(e))
        return {
            'statusCode': 500,
            'body': json.dumps(f"Error: {str(e)}")
        }
