import cv2
import numpy as np
import serial
import tensorflow as tf

# Load TFLite model
interpreter = tf.lite.Interpreter(model_path="waste_model.tflite")
interpreter.allocate_tensors()

input_details = interpreter.get_input_details()
output_details = interpreter.get_output_details()

# Serial communication with Arduino
ser = serial.Serial('/dev/ttyUSB0', 9600)

# Class names
classes = ["cardboard", "glass", "metal", "paper", "plastic", "trash"]

# Open camera
cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()

    if not ret:
        break

    img = cv2.resize(frame, (224,224))
    img = img / 255.0
    img = np.expand_dims(img, axis=0).astype(np.float32)

    interpreter.set_tensor(input_details[0]['index'], img)
    interpreter.invoke()

    output = interpreter.get_tensor(output_details[0]['index'])

    pred = classes[np.argmax(output)]

    print("Prediction:", pred)

    # Convert to BIO / NONBIO
    if pred in ["paper", "cardboard"]:
        ser.write(b"BIO\n")
    else:
        ser.write(b"NONBIO\n")

    cv2.imshow("Camera", frame)

    if cv2.waitKey(1) & 0xFF == 27:
        break

cap.release()
cv2.destroyAllWindows()
