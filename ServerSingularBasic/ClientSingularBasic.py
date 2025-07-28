import socket  # Library for socket programming, requires pip install or pycharm packages
import keyboard  # Library to capture keyboard events, requires pip install or pycharm packages

# Configuration: Replace with the actual server's IP address and port
server_ip = '10.171.224.197'  # Arduino server's IP address
server_port = 12345           # Port where the server is listening

try:
    # Create a socket object and establish a connection to the server
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client_socket:
        print(f"Connecting to server at {server_ip}:{server_port}...")
        client_socket.connect((server_ip, server_port))  # Attempt to connect
        print("Connected successfully.")  # Log successful connection

        # Initialize an empty buffer for collecting typed characters
        buffer = ""

        # Infinite loop to capture and process keyboard inputs
        while True:
            # Wait for a key event (key press or release)
            event = keyboard.read_event()
            if event.event_type == keyboard.KEY_DOWN:  # Only process key press events
                key = event.name  # Get the key's name

                # Check for exit condition
                if key == 'esc':  # Exit the loop when 'esc' is pressed
                    print("Exiting...")
                    break

                # Handle special keys
                if len(key) > 1:  # Process special keys like space or enter
                    if key == 'space':
                        key = ' '  # Replace "space" with a space character
                    elif key == 'enter':  # Send the entire buffer on Enter key
                        client_socket.sendall(buffer.encode('utf-8'))  # Send the complete buffer
                        print(f"Sent: {buffer}")  # Log the sent string
                        buffer = ""  # Clear the buffer after sending
                        continue
                    else:
                        continue  # Ignore unsupported special keys

                # Append regular keys to the buffer
                buffer += key
                print(f"Buffer: {buffer}")  # Log the current buffer contents

except Exception as e:
    # Handle any errors that occur during execution
    print(f"An error occurred: {e}")