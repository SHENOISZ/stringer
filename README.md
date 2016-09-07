# stringer
### C ++ header with a focus on string manipulation

// tests

// String  str

```
string text = "desenvolvendo software com C++";

// split with char
cout << str.split('e', text)[4] << endl;
// $: com C++

// split with string
cout << str.split("com", text)[1] << endl;
// $: C++

// array count
cout << str.len(str.split('e', text)) << endl;
// $:4
```
<br>
```
// format text
string fac[] = {"pro", "com", "C++", "NULL"};
string comum = "{0}gramando {1} {2}";

comum = str.format(comum, fac);

cout << comum << endl;
// $:programando com C++
```
<br>
```
string text = "desenvolvendo software com C++";

// count string
cout << str.length(text) << endl;
// $:29
```
<br>
```
string text = "desenvolvendo software com C++";

// replace char
cout << str.replace('l', 'u', text) << endl;
// $:desenvouvendo software com C++

// replace char all
cout << str.replaceAll('e', 'w', text) << endl;
// $:dwswnvolvwndo softwarw com C++

// replace string
cout << str.replace("C++", "C-plusplus", text) << endl;
// $:desenvolvendo software com C-plusplus

// replace string all
cout << str.replaceAll("en", "EN", text) << endl;
// $:desENvolvENdo software com C++
```
<br>
```
string text = "desenvolvendo software com C++";

// get part string
cout << str.substr(0, 13, text) << endl;
// $:desenvolvendo
```
<br>
```
string fac[] = {"pro", "com", "C++", "NULL"};

// if exist "C++" in array: true; if not in array: false
cout << str.exists("C++", fac) << endl;
```
<br>
```
string text = "desenvolvendo software com C++";

// count a char in string
cout << str.charCount('e', text) << endl;
// $: 3
```
<br>
```
string text = "desenvolvendo software com C++";

// return positions of 'e' in string
int *maps = str.charMap('e', text);

cout << "char position:"
    << maps[0] << " position:"
    << maps[1] << " position:"
    << maps[2] << endl;

// $:char position:1 position:3 position:9
```
<br>
```
string text = "desenvolvendo software com C++";

// return position of "en" in string
cout << str.find("en", text)->index() << endl;
// $:3

// return positions of "en" in string
int *Maps = str.find("en", text)->indexes();

cout << "string position:"
    << Maps[0] << " position:"
    << Maps[1] << endl;

// $:string position:3 position:9

// count "en" exist in string
cout << str.find("en", text)->counter() << endl;
// $:1

// if "en" exists in string return true; if not false
cout << str.find("en", text)->exists() << endl;
// $:true
```
<br>
```
// conversion types
cout << str.toInt("17")
    << " - " << str.toFloat("17.4")
    << " - " << str.toDouble("17.4")
    << " - " << str.toString(17)
    << " - " << str.toString(17.4) << endl;
```

### LICENSE MIT