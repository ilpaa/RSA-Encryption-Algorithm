#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int power(int x, unsigned int y, int p)
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int *RSA_encrypt(string msg, int e, int n)
{
    int *encrypted_text = new int[msg.length()]; // Use msg.length() as the size
    int k = 0;

    for (int i = 0; i < msg.length(); i++)
    {
        // Convert each character to ASCII value
        int ascii = int(msg[i]);
        // Encrypt the ASCII value and store in encrypted_text array
        encrypted_text[k] = power(ascii, e, n);
        k++;
    }

    return encrypted_text;
}

string RSA_decrypt(int encrypted_text[], int d, int n)
{
    string mssge;
    for (int i = 0; i < 100; i++)
    {
        // Decrypt each value and convert to ASCII
        int decrypted_value = power(encrypted_text[i], d, n);
        // Ensure the decrypted value is in the valid ASCII range
        decrypted_value = decrypted_value % 256;
        // Add to string
        mssge += char(decrypted_value);
    }
    return mssge;
}

int main()
{
    int p, q, n, phi, e = 3, d;

    cout << "\nEnter the value of p: ";
    cin >> p;

    for (int i = 2; i < p; i++)
    {
        if (p % i == 0)
        {
            cout << "p is not prime\n";
            cout << "enter p: ";
            cin >> p;
        }
    }

    cout << "Enter the value of q: ";
    cin >> q;

    if (p != q)
    {
        for (int i = 2; i < q; i++)
        {
            if (q % i == 0)
            {
                cout << "q is not prime\n";
                cout << "enter q: ";
                cin >> q;
            }
        }
    }

    cout << "Enter a message to encrypt: ";
    string msg;
    cin >> msg;

    n = p * q;
    phi = (p - 1) * (q - 1);

    // Calculate d based on e and phi
    // Note: This is a simplified approach and might not be secure for real-world applications
    d = 0;
    while ((e * d) % phi != 1)
    {
        d++;
    }

    cout << "Public Key (e , n) = (" << e << " , " << n << ")" << endl;

    int *cipher = RSA_encrypt(msg, e, n);
    cout << "Encrypted message: ";
    for (int i = 0; i < msg.length(); i++)
        cout << cipher[i] << " ";

    string decr_msg;
    decr_msg = RSA_decrypt(cipher, d, n);
    cout << "\nDecrypted Message: " << decr_msg << endl;

    // Don't forget to free the allocated memory
    delete[] cipher;

    return 0;
}
