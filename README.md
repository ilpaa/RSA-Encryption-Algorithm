# RSA Encryption and Decryption Program

## Introduction

This program is a demonstration of the RSA (Rivest-Shamir-Adleman) encryption and decryption algorithm, a widely utilized public-key cryptosystem. The RSA algorithm involves the use of two keys: a public key for encryption and a private key for decryption.

## Features

- **Key Generation:** The program generates public and private keys based on user-input prime numbers (`p` and `q`).
- **Encryption:** Converts each character of the input message into its ASCII value and encrypts it using the RSA algorithm.
- **Decryption:** Decrypts the encrypted values back to ASCII and reconstructs the original message.

## Usage

1. **Prime Numbers:**
   - Enter two prime numbers (`p` and `q`) to generate the public and private keys.
   - The program checks the primality of the provided numbers.

2. **Key Generation:**
   - The program computes the public key `(e, n)` and the private key `d`.

3. **Encryption:**
   - Each character of the input message is converted to its ASCII value.
   - The ASCII values are encrypted using the public key.

4. **Decryption:**
   - The encrypted values are decrypted using the private key.
   - The decrypted ASCII values are converted back to characters.

5. **Security Note:**
   - The program provides a simplified demonstration for educational purposes.
   - Real-world RSA implementations involve more sophisticated key generation and security measures.

## How it Works

### Key Generation

- Calculate `n = p * q`, where `p` and `q` are prime numbers.
- Compute Euler's totient function: `phi = (p-1) * (q-1)`.
- Find a public exponent `e` such that `1 < e < phi` and `gcd(e, phi) = 1`.
- Calculate the private exponent `d` as the modular multiplicative inverse of `e` modulo `phi`.

### Encryption

- Convert each character of the input message to its ASCII value.
- Encrypt each ASCII value using the public key `(e, n)` with the formula: `ciphertext = (plaintext^e) mod n`.

### Decryption

- Decrypt each encrypted ASCII value using the private key `d` with the formula: `plaintext = (ciphertext^d) mod n`.
- Convert each decrypted ASCII value back to its character representation.

## Security Considerations

- The program uses a simplified method to calculate `d`, which may not be secure for real-world applications.
- In practice, secure key generation and management are critical aspects of RSA implementation.

## How to Run

1. **Compile and Run:**
   - Compile the program using a C++ compiler.
   - Run the compiled executable.

2. **User Input:**
   - Follow the prompts to enter prime numbers (`p` and `q`) and a message for encryption.

3. **Output:**
   - Observe the encrypted and decrypted messages.

Feel free to explore and modify the code to enhance your understanding of RSA encryption.

