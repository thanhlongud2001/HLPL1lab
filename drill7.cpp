#include "std_lib_facilities.h"

#define k 1000 // drill 6
constexpr char number = '8';
constexpr char quit = 'q';
constexpr char print = ';';
constexpr char name = 'a';
constexpr char let = 'L';
constexpr char result = '=';

const char Sqrt = 's';//drill 7
const char Pow = 'p';

const string declkey = "let";
const string prompt = ">";

double expression();
double primary();
double term();
double declaration();
double statement();

class Variable {
public:
    string name;
    double value;
};

vector<Variable> var_table;

bool is_declared(string var) {
    for (const Variable& v : var_table)
        if (v.name == var) return true;
    return false;
}

double define_name(string var, double val) {
    if (is_declared(var)) error(var,"declared twice");
    var_table.push_back(Variable{var,val});
    return val;
}

double get_value(string s) {
    for (const auto& v : var_table)
        if (v.name == s) return v.value;
    error("get: undefined variable",s);
    return -1;
}

void set_value(string s, double d) {
    for (auto& v : var_table)
        if (v.name == s) {
            v.value = d;
            return;
        }
    error("set: undefined variable", s);
}

class Token {
public:
    char kind;
    double value;
    string name;
    Token(): kind(0) {}
    Token (char ch): kind(ch), value(0) {}
    Token (char ch, double val): kind(ch), value(val) {}
    Token (char ch, string n): kind(ch), name(n) {}
};

class Token_stream {
public:
    Token_stream();
    Token get();
    void putback(Token t);
    void ignore(char c);
private:
    bool full;
    Token buffer;
};

Token_stream::Token_stream(): full(false), buffer(0) {}

void Token_stream::putback(Token t) {
    if(full) error("Token_stream buffer full");
    buffer = t;
    full = true;
}

void Token_stream::ignore(char c) {
    if (full && c == buffer.kind) {
        full = false;
        return;
    }
    full = false;

    char ch = 0;
    while (cin >> ch)
        if (ch == c) return;
}

Token Token_stream::get() {
    if(full) {
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;

    switch(ch) {
        case quit:
        case print:
        case '(':
        case ')':
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '=':
        case ',': //added to be used in pow()
            return Token(ch);
        case '.':
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9': {
            cin.putback(ch);
            double val;
            cin >> val;
            return Token(number, val);
        }
        default: {
            if (isalpha(ch)) {
                string s;
                s += ch;
                while (cin.get(ch) && (isalpha(ch) || isdigit(ch)))
                    s += ch;
                cin.putback(ch);
                if (s == "#" || s == declkey) return Token(let);//drill 10
                if (s == "exit") return Token(quit);//task 11
                if (s == "sqrt") return Token(Sqrt);//drill 7
                if (s == "pow") return Token(Pow);//drill 9
                else if (is_declared(s))
                    return Token(number, get_value(s));
                return Token{name, s};
            }
            error("Bad token");
        }
            return 0;
    }
}

Token_stream ts;
double expression();

double primary() {
    Token t = ts.get();
    switch (t.kind) {
        case '(': {
            double d = expression();
            t = ts.get();
            if (t.kind != '(') error("')' expected");
            return d;
        }
        case number:
            return t.value;
        case name:
            return get_value(t.name);
        case '-':
            return - primary();
        case '+':
            return primary();
        //drill 7
        case Sqrt: {
            t = ts.get();
            if (t.kind != '(')
                error(" '(' was expected.");
            double d = expression();
            if (d < 0)
                error("negative number");//drill 8
            t = ts.get();
            if (t.kind != ')')
                error(" ')' was expected.");

            return sqrt(d);
        }

        //drill 9
        case Pow: {
            t = ts.get();//for (
            if (t.kind != '(')
                error(" '(' was expected.");
            double d = expression();// for number
            t = ts.get();// for comma
            if (t.kind != ',')
                error(" ',' was expected.");
            double i = expression();// for i
            t = ts.get();//for )
            if (t.kind != ')')
                error(" ')' was expected.");

            return pow(d, i);
        }
        default:
            ts.putback(t);
            error("primary expected");
    }
    return -1;
}

double term() {
    double left = primary();
    Token t = ts.get();

    while (true) {
        switch (t.kind) {
            case '*':
                left *= primary();
                t = ts.get();
                break;
            case '/': {
                double d = primary();
                if (d == 0) error("can't be divide by zero");
                left /= d;
                t = ts.get();
                break;
            }
            case '%': {
                double d = primary();
                if (d == 0) error("divide by zero");
                left = fmod(left, d);
                t = ts.get();
                break;
            }
            default:
                ts.putback(t);
                return left;
        }
    }
}

double expression() {
    double left = term();
    Token t = ts.get();
    while (true){
        switch (t.kind) {
            case '+':
                left += term();
                t = ts.get();
                break;
            case '-':
                left -= term();
                t = ts.get();
                break;
            default:
                ts.putback(t);
                return left;
        }
    }
}

double declaration() {
    Token t = ts.get();
    if (t.kind != name) error("name expected in declaration");
    string var_name = t.name;

    Token t2 = ts.get();
    if (t2.kind != '=') error("= missing in declaration of ",var_name);

    double d = expression();
    define_name(var_name,d);
    return d;
}

double statement() {
    Token t = ts.get();
    switch (t.kind) {
        case let:
            return declaration();
        default:
            ts.putback(t);
            return expression();
    }
}

void clean_up_mess() {
    ts.ignore(print);
}

void calculate() {
    while (cin) {
        try {
            cout << prompt;
            Token t = ts.get();
            while (t.kind == print) t = ts.get();
            if (t.kind == quit) return;
            ts.putback(t);
            cout << result << statement() << endl;
        }
        catch (exception &e) {
            cerr << e.what() << endl;
            clean_up_mess();
        }
    }
}

int main() {
    try {
        define_name("pi", 3.1415926535);
        define_name("e", 2.7182818284);

        calculate();
        keep_window_open();
        return 0;
    }

    catch (exception& e) {
        cerr << e.what() << endl;
        keep_window_open("~~");
        return 1;
    }
    catch (...) {
        cerr << "exception\n";
        keep_window_open("~~");
        return 2;
    }
}
