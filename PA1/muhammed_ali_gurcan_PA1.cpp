#include <iostream> 
#include <cstdlib> 
#include <ctime> 

using namespace std;

const int MAX_DIGITS = 15; // Maximum number of digits
const char DIGITS[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e'}; 

// generating a secret number
void generateSecretNumber(int N, char secretNumber[]) {
    srand(time(0)); //seed for random number generation
    int digit = 0;
    do {
        digit = rand() % (MAX_DIGITS - 1) + 1; // generating first digit (cannot be 0)
        secretNumber[0] = DIGITS[digit];
    } while (secretNumber[0] == '0');
    bool usedDigits[15] = {false}; // array to keep track of used digits
    usedDigits[digit] = true;
    
    for (int i = 1; i < N; i++) {
        do {
            digit = rand() % MAX_DIGITS;
        } while (usedDigits[digit]); // ensure unique digits
        secretNumber[i] = DIGITS[digit];
        usedDigits[digit] = true;
    }
}

// checking if a number is valid
bool isValidNumber(const char number[], int length) {
    if (length > MAX_DIGITS || number[0] == '0') // check for maximum length and leading zero
        return false;

    bool digits[15] = {false}; // array to track used digits
    for (int i = 0; i < length; i++) {
        if (number[i] < '0' || (number[i] > '9' && number[i] < 'a') || number[i] > 'e') // checking for valid characters
            return false;
        int index = (number[i] >= 'a') ? (number[i] - 'a' + 10) : (number[i] - '0'); // converting character to index
        if (digits[index])
            return false; // Check for repeated digits
        digits[index] = true;
    }
    return true;
}

// calculating the length of a string
int strLength(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// copying
void strCopy(const char* copy, char* paste) {
    int i = 0;
    while (copy[i] != '\0') {
        paste[i] = copy[i];
        i++;
    }
    paste[i] = '\0';
}

// hints based on secret and guess
void getHints(const char secret[], const char guess[], int length, int& Cexact, int& Cmisplaced) {
    Cexact = 0;
    Cmisplaced = 0;
    int secretCount[MAX_DIGITS] = {0};
    int guessCount[MAX_DIGITS] = {0};

    for (int i = 0; i < length; i++) {
        if (secret[i] == guess[i]) {
            Cexact++; // count exact matches
        }
        else {
            int secretIndex = (secret[i] >= 'a') ? (secret[i] - 'a' + 10) : (secret[i] - '0'); // convert character to index
            int guessIndex = (guess[i] >= 'a') ? (guess[i] - 'a' + 10) : (guess[i] - '0'); // convert character to index
            secretCount[secretIndex]++;
            guessCount[guessIndex]++;
        }
    }

    for (int i = 0; i < MAX_DIGITS; i++) {      
        Cmisplaced += (secretCount[i] < guessCount[i]) ? secretCount[i] : guessCount[i]; // count misplaced digits
    }
}

// main function
int main(int argc, char *argv[]) {

    if (argc != 3) 
    { // checking for correct number of arguments
        cerr << "E0" << endl; // incorrect arguments
        return 0;
    }

    // Check if mode is valid
    if (argv[1][0] != '-' || (argv[1][1] != 'r' && argv[1][1] != 'u')) {
        cerr << "E0" << endl; // invalid mode
        return 0;
    }

    char secret[MAX_DIGITS + 1]; // secret number
    int secretLength = 0;
    if (argv[1][0] == '-' && argv[1][1] == 'r')
    { // Random mode
        int N = atoi(argv[2]); // convert string to integer
        if (N <= 0 || N > MAX_DIGITS) {
            cerr << "E0" << endl; // invalid number of digits
            return 0;
        }
        generateSecretNumber(N, secret);
        secretLength = N;
    }
    else if (argv[1][0] == '-' && argv[1][1] == 'u')
    {   // User input mode
        int arg2Length = strLength(argv[2]);
        if (!isValidNumber(argv[2], arg2Length)) {
            cerr << "E0" << endl; // invalid user input
            return 0;
        }
        strCopy(argv[2], secret);
        secretLength = arg2Length;
    } 
    else{
        cerr << "E0" << endl; // error for invalid 
        return 0;
    }

    int turn = 1; // Turn counter
    while (turn <= 100) {
        char guess[MAX_DIGITS + 1]; // guessed number
        cin >> guess; // input guess
        int guessLength = strLength(guess);
        if (guessLength != secretLength)
        {
            cout << "E1" << endl; // incorrect length of guess
            return 0;
        }

        if (!isValidNumber(guess, guessLength))
        {
            cout << "E2" << endl; // invalid guess
            return 0;
        }

        int Cexact, Cmisplaced; // variables to store hints
        getHints(secret, guess, secretLength, Cexact, Cmisplaced); // get hints
        
        if (Cexact != secretLength)
        {
            cout << Cexact << " " << Cmisplaced << endl; // output hints
        }

        if (Cexact == secretLength) 
        {
            cout << "FOUND " << turn << endl; // output success message
            return 0;
        }
        turn++; // Increment turn counter
    }

    cout << "FAILED" << endl; // output failure message
    return 0;
}
