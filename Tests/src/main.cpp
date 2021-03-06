#include <iostream>
#include "stringer.hpp"

using namespace std;
using namespace shenoisz;

int main(int argc, const char* argv[])
{
    // tests

    // String  str

    string text = "desenvolvendo software com C++";

    // split with char
    cout << str.split('e', text)[4] << endl;
    // ~$: com C++

    // split with string
    cout << str.split("com", text)[1] << endl;
    // ~$: C++

    // array count
    cout << str.len(str.split('e', text)) << endl;
    // ~$:4

    cout << "\n============================================\n" << endl;

    // format text
    string fac[] = {"pro", "com", "C++", "NULL"};
    string comum = "{0}gramando {1} {2}";

    comum = str.format(comum, fac);

    cout << comum << endl;
    // ~$:programando com C++

    cout << "\n============================================\n" << endl;
    // count string
    cout << str.length(text) << endl;
    // ~$:29

    cout << "\n============================================\n" << endl;

    // replace char
    cout << str.replace('l', 'u', text) << endl;
    // ~$:desenvouvendo software com C++

    // replace char all
    cout << str.replaceAll('e', 'w', text) << endl;
    // ~$:dwswnvolvwndo softwarw com C++

    // replace string
    cout << str.replace("C++", "C-plusplus", text) << endl;
    // ~$:desenvolvendo software com C-plusplus

    // replace string all
    cout << str.replaceAll("en", "EN", text) << endl;
    // ~$:desENvolvENdo software com C++

    cout << "\n============================================\n" << endl;

    // get part string
    cout << str.substr(0, 13, text) << endl;
    // ~$:desenvolvendo

    cout << "\n============================================\n" << endl;

    // if exist "C++" in array of Char: true; if not in array: false
    string example = "programming with C++";
    cout << str.exists("C++", example) << endl;
    // ~$:true

    // if exist "C++" in array of string: true; if not in array: false
    string frases[] = {"Developer", "C++", "C", "NULL"};
    cout << str.exists("C++", frases) << endl;
    // ~$:true

    cout << "\n============================================\n" << endl;

    // count a char in string
    cout << str.charCount('e', text) << endl;
    // ~$: 3

    cout << "\n============================================\n" << endl;

    // return positions of 'e' in string
    int *maps = str.charMap('e', text);

    cout << "char position:"
        << maps[0] << " position:"
        << maps[1] << " position:"
        << maps[2] << endl;

    // ~$:char position:1 position:3 position:9

    cout << "\n============================================\n" << endl;

    // return position of "en" in string
    cout << str.find("en", text)->index() << endl;
    // ~$:3

    // return positions of "en" in string
    int *Maps = str.find("en", text)->indexes();

    cout << "string position:"
        << Maps[0] << " position:"
        << Maps[1] << endl;

    // ~$:string position:3 position:9

    // count "en" exist in string
    cout << str.find("en", text)->counter() << endl;
    // ~$:1

    cout << "\n============================================\n" << endl;

    // conversion types
    cout << str.toInt("17")
        << " - " << str.toFloat("17.4")
        << " - " << str.toDouble("17.4")
        << " - " << str.toString(17)
        << " - " << str.toString(17.4) << endl;

    // ~$:17 - 17.4 - 17.4 - 17 - 17.4

    // from char for string
    char caract = 'f';

    string tre = str.toString(caract);

    cout << tre << endl;
    // ~$:f

    string frase = "Text for test";

    const char* contant = str.toConst(frase);

    cout << contant << endl;
    // ~$:Text for test

    cout << "\n============================================\n" << endl;

    // remove char in string
    cout << str.remove('t', "testing") << endl;
    // ~$:esting

    // remove all char in string
    cout << str.removeAll('t', "testing") << endl;
    // ~$:esing

    // remove string in string
    cout << str.remove("te", "testing more a test") << endl;
    // ~$:sting more a test

    // remove all string in string
    cout << str.removeAll("te", "testing more a test") << endl;
    // ~$:sting more a st

    // remove a array string of string
    string regex[] = {"e", "t", "g", "NULL"};

    cout << str.ex_remove(regex, "testing") << endl;
    // ~$:stin

    // remove a array string of string
    string regex_[] = {"e", "t", "g", "NULL"};

    cout << str.ex_removeAll(regex_, "testing") << endl;
    // ~$:sin

    return 0;
}