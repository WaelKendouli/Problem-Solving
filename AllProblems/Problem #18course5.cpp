#include <iostream>
#include<string>
using namespace std;
string ReadText(string str)
{
    string text;
    cout << str << endl;
    getline(cin, text);
    return text;
}
string EncryptText(string& text , short int EncryptionKey)
{
    for (int i = 0; i <= text.length() ; i++)
    {
        text[i] = char((int)text[i] + EncryptionKey);
    }
    return text;
}

string DescryptionText(string &Text , short int EncryptionKey)
{

    for (int i = 0; i <= Text.length() ; i++)
    {
        Text[i] = char((int)Text[i] - EncryptionKey);

    }
    return Text;
}

int main()
{
    const short int EncryptionKey = 2;
    string Text = ReadText("Your Name :");
    string EncryptedText = EncryptText(Text, EncryptionKey);
    string DiscryptedText = DescryptionText(Text, EncryptionKey);
    cout << "Text before Encyption : " << Text<<endl;
    cout << " Text After Encyption : " << EncryptedText<<endl;
    cout << " Text After Descyption : " << DiscryptedText << endl;

    return 0;
}


