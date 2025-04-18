#include "./String.h"

using namespace std;

int main() {

    String s = "Hello";
    cout<<s;
    int key = 311;

    String ciphertext = s.cipher(key);
    cout<<endl<<ciphertext;

    String deciphertext = ciphertext.decipher(key);
    cout<<endl<<deciphertext;
    return 0;
}