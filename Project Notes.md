ds vector works -- yay!

questions for lab:
- why are extra characters printing? it's printing off the array

how to test memory management:
valgrind is way to test 
--> change "executable" to name of executable file 
--> look for lost bytes
--> free() is the c way of saying new/delete
--> read from bottom up because the top is a bunch of jibberish
--> memory management problems will still compile & run
--> "leak summary" is bad news bc memory is leaking ahh
1) go to terminal on server
2)ls
3)cd (make sure executable is in the build folder)
4)then name the program

*if you don't have a delete your program will still compile and run 
*it might be more helpful for memory management 
*characters are encoded as unicode so they vary in length, therefore
    a different locale may not work as well for the cstring functions like strcpy
    - so use for loops to copy character by character in
    - for loop that goes until '/0'


        //len = sizeof(userstr)/sizeof(char); //basically divides by 8 to get string length
    strcpy(string,userstr); //may need to implement a for loop


Need to figure out this whole len thing
//break up a string into words

DSSTRING & DSVECTOR TEST CODE
//INSERTION & EXTRACTION OPERATORS
    DSString subject = "Data Structures";
    DSString name;

    cout << "Welcome to " << subject << "!" << endl;
    cout << "Enter your name:";
    cin >> name;
    cout << name << endl;
    name = "white";
    cout << name << endl;

    //STRING CONSTRUCTION, ASSIGNMENT, EXTRACTION
    DSString aStr;
    DSString bStr;
    aStr = "Hello World";
    bStr = "Bye";
    cout << aStr << endl;
    cout << bStr << endl;

    //DSVECTOR OF DSSTRINGS
    DSVector<int> a = {2,7,5,10,32};
    DSVector<int> b = {3,8,6,11,33};
    
    cout << a[0] << endl;
    for (size_t i = 0; i < a.size(); i++){
        a[i]= a[i] * 3;
        cout << a[i] << " ";
    }
    cout << endl;

    for (size_t i = 0; i < b.size(); i++){
        cout << b[i] << " ";
    }
    cout << endl;

    DSVector<int> d(a);
    for (size_t i = 0; i < d.size(); i++){
        cout << d[i] << " ";
    }
    cout << endl;



    DSString myString = "Hello, World!";
    cout << myString << endl;

    // this uses the one argument constructor in DSString and then the inherited operator=
    myString = "Good bye!";
    cout << myString << endl;

    cout << "substr: " << myString.substring(5,3) << endl;
    cout << "length: " << myString.length() << endl;

    DSString e = "test";
    DSString f = e;
    cout << f << endl;

    cout << boolalpha; //this makes a bool say true or false (rather than 1 or 0)
    cout << (e == f) << endl;
    
    
    // use initialization list (see DSVector.h)
    DSVector<DSString> strings = {
        DSString("bbb"),
        DSString("aaa"),
        DSString("ddd"),
        DSString("eee"),
        DSString("ccc")};
    bool test = strings[0] > strings[1];
    cout << test << endl;

    // find strings
    for (const auto &s : strings)
        cout
            << s << "\n";

    //what is the != for?
    cout << "found ddd: " << (find(strings.begin(), strings.end(), DSString("ddd")) != strings.end()) << endl;
    cout << "found zzz: " << (find(strings.begin(), strings.end(), DSString("zzz")) != strings.end()) << endl;

    // sorting
    sort(strings.begin(), strings.end()); //how to get this to sort?

    for (const auto &s : strings)
        cout
            << s << "\n";

    // now we can do more efficient search
    cout << "found ddd: " << binary_search(strings.begin(), strings.end(), DSString("ddd")) << endl;
    cout << "found zzz: " << binary_search(strings.begin(), strings.end(), DSString("zzz")) << endl;
    

    /*DSString full;
    cout << "What is your full name?" << endl;
    full.gline(cin);
    cout << full;*/

    //cmake ..  < make sure you're in build folder>
    //make
    // ./sentiment "file path"

./sentiment -- 0
train -- 1 

While(!inFile.eof())

1. read function 
2. count function (what words are positive and negative)
    positive words and negative words vector in driver class

tweet class constructor -- can take out stop words

what I'm working on rn:
- how to read each line of the train data set 
- parsing each line of data set 
- storing important information from the line (sentiment, id, tweet)
- how to break apart each tweet into individual words 
- count each word's appearance in positive or negative tweets
    - could count pos or neg appearances 
    - OR could count bias (increment/ decrement same variable)
        - this would result in a "score" for each word
            - this might make training more effective 

tokenize with a substring

/*
    DSString *ptr = find(tmpLib.begin(), tmpLib.end(), "to");
    if (ptr != tmpLib.end())
        cout << "Element found at Index : " << ptr << endl;
    else
        cout << "Element not found" << endl;

    */