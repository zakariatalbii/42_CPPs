# 🗺️ 42 C++ Modules

<p align="center">
  <strong>From C++ fundamentals to templates, STL, parsing, and algorithmic problem solving.</strong>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-C%2B%2B98-00599C?style=flat-square&logo=c%2B%2B&logoColor=white" alt="C++98" />
  <img src="https://img.shields.io/badge/42-Curriculum-000000?style=flat-square" alt="42" />
  <img src="https://img.shields.io/badge/Modules-CPP00--CPP09-6C63FF?style=flat-square" alt="CPP00-CPP09" />
  <img src="https://img.shields.io/badge/Build-Make-427819?style=flat-square" alt="Make" />
</p>

---

## 📚 About

This repository contains my implementation of the **42 C++ Modules**, from `CPP00` through `CPP09`.

The project is built progressively: it starts with classes and object lifetime, then moves through references, pointers, fixed-point arithmetic, inheritance, polymorphism, exceptions, casts, templates, STL containers and algorithms, and finally parsing and algorithmic problem solving.

Every exercise is implemented as an independent program with its own `Makefile`.

The code follows the **C++98** standard and is compiled with:

```text
-Wall -Wextra -Werror -std=c++98
```

---

## 🧭 How to Read This README

For every module, the structure is:

1.  **Goal / concept**
2.  **Exercise-by-exercise implementation**
3.  **Important code decisions**
4.  **What was learned**
5.  **How the exercises connect to the next module**

The explanations focus on the actual implementation:

-   class members
-   constructors/destructors
-   function responsibilities
-   data flow
-   ownership
-   references/pointers
-   STL usage
-   error handling
-   algorithms

This is therefore closer to a **personal technical study log** than a
generic C++ tutorial.

---

# CPP00 --- C++ Basics and Classes

## 💡 Main Ideas

`CPP00` establishes the basic C++ environment:

-   `std::string`
-   `std::cout` / `std::cin`
-   classes and objects
-   private/public members
-   constructors and destructors
-   member functions
-   header files
-   multiple source files
-   `Makefile`
-   C++98 compilation

The important transition is from procedural C-style code toward
object-oriented C++.

---

## ex00 --- Megaphone

### 📂 Files

``` text
CPP00/ex00/
├── Makefile
└── megaphone.cpp
```

### ⚙️ Implementation

`main()` receives `argc` and `argv`.

If there are command-line arguments:

1.  Start at `argv[1]`.
2.  Copy each argument into a `std::string`.
3.  Iterate over every character.
4.  Convert it with `std::toupper`.
5.  Print it.

If there are no arguments, the program prints the predefined feedback
message.

Finally, a newline is printed and `0` is returned.

### 🔎 Important Detail

The implementation uses:

``` cpp
std::string s;
```

and then:

``` cpp
s = argv[i];
```

This demonstrates conversion from the C-style argument array into a C++
string object.

The inner loop uses `size_t` because `std::string::length()` returns a
size-related unsigned type.

### 🎓 What Is Learned

-   Command-line arguments
-   `std::string`
-   character processing
-   `<cctype>`
-   basic loops
-   namespaces
-   C++ stream output

---

## ex01 --- PhoneBook

This is the first exercise where the project becomes a real multi-class
C++ program.

### 🏗️ Architecture

``` text
PhoneBook
   |
   +-- Contact[8]
```

`PhoneBook` owns a fixed array of eight `Contact` objects.

The project also separates utility functions into:

``` text
utils.hpp
utils.cpp
```

### 👤 Contact

`Contact` stores:

-   first name
-   last name
-   nickname
-   phone number
-   darkest secret

The members are private, so outside code cannot directly modify them.

The public interface is:

``` cpp
bool set(int i);
const std::string &get(int i) const;
```

The integer selects which field is being manipulated.

### 📱 PhoneBook

`PhoneBook` contains:

``` cpp
Contact contact[8];
int index;
int count;
```

`index` tracks how many usable entries currently exist.

`count` tracks where the next `ADD` should write.

When `count` reaches eight, it returns to zero. This creates a circular
storage model: new contacts overwrite the oldest slot once the phonebook
is full.

### `add()`

The function asks for five fields one by one.

For each field:

``` cpp
if (!contact[count].set(...))
    return;
```

A failed field aborts the addition.

Only after all five fields succeed:

``` cpp
count++;
```

and:

``` cpp
if (count == 8)
    count = 0;
```

The number of visible entries is also increased until eight.

### `search()`

The function:

1.  Checks whether the phonebook is empty.
2.  Prints a formatted table.
3.  Displays each contact with `tenChar()`.
4.  Requests an index.
5.  Prints the complete selected contact.

### 🧰 Utility Layer

`utils.cpp` centralizes validation and formatting:

-   `getLine()` reads a line
-   `prompt()` handles commands
-   `isPrint()` checks printable content
-   `emptyField()` rejects empty input
-   `isNum()` validates numeric input
-   `tenChar()` truncates/formats table fields
-   `promptIndex()` validates a selected index

### 🎓 What Is Learned

This exercise introduces the practical structure of a C++ project:

``` text
header
  ↓
class declaration
  ↓
source implementation
  ↓
main
  ↓
Makefile
```

It also teaches encapsulation, object composition, input validation and
a fixed-size circular data structure.

---

# CPP01 --- Memory, References, Streams and Pointers

`CPP01` moves from basic classes into object lifetime and indirection.

---

## ex00 --- Zombie

### 📂 Files

``` text
Zombie.hpp
Zombie.cpp
newZombie.cpp
randomChump.cpp
main.cpp
```

The important distinction is between:

-   an object created dynamically
-   an object created automatically on the stack

`newZombie()` returns a pointer because the zombie is dynamically
allocated.

`randomChump()` creates the zombie as a local automatic object.

The exercise therefore demonstrates that **where an object is created
changes how its lifetime is managed**.

### Learned

-   stack lifetime
-   dynamic allocation
-   pointers
-   `new`
-   `delete`
-   constructors/destructors
-   returning dynamically allocated objects

---

## ex01 --- Zombie Horde

The next step is dynamic allocation of an array.

The implementation creates several `Zombie` objects together.

The important lesson is that:

``` cpp
new Zombie[N]
```

requires the matching:

``` cpp
delete []
```

rather than plain `delete`.

This exercise makes array ownership explicit.

---

## ex02 --- References

The implementation demonstrates the relationship between:

``` cpp
std::string
std::string &
std::string *
```

The program prints the same logical object through:

-   the value
-   the address
-   a reference

The important concept is that a reference is an alias to an existing
object rather than a separate object.

---

## ex03 --- Weapon, HumanA and HumanB

This exercise is especially useful for understanding references and
pointers through a real design.

### 🔫 Weapon

`Weapon` stores its type.

It exposes:

``` cpp
const std::string &getType() const;
void setType(const std::string &weaponType);
```

### 🧑 HumanA

`HumanA` stores:

``` cpp
Weapon &weapon;
```

The weapon reference must exist when `HumanA` is constructed.

### 🧑 HumanB

`HumanB` stores a pointer:

``` cpp
Weapon *weapon;
```

This permits a different state: `HumanB` can exist before a weapon is
assigned.

### 🧠 Core Lesson

Reference:

-   must refer to an existing object
-   cannot be reseated
-   is appropriate when the relationship is mandatory

Pointer:

-   can be changed
-   can represent "no object"
-   is appropriate when the relationship can be optional

This is one of the most important design lessons in the module.

---

## ex04 --- Sed replacement

The program reads:

``` text
filename
s1
s2
```

Then creates:

``` text
filename.replace
```

The implementation uses:

-   `std::ifstream` for reading
-   `std::ofstream` for writing
-   `std::string::find`
-   `std::string::substr`

The replacement helper searches for occurrences of the target string and
writes the replacement into the output stream.

### Learned

-   file streams
-   stream state
-   reading files
-   writing files
-   string searching
-   substring manipulation
-   separating replacement logic from `main()`

---

## ex05 --- Harl

`Harl` has four member functions:

``` text
debug()
info()
warning()
error()
```

The program selects a member function based on a string level.

This introduces **pointers to member functions**.

Conceptually:

``` text
string
  ↓
select member-function pointer
  ↓
invoke member function
```

This is different from an ordinary function pointer because the target
belongs to a class.

---

## ex06 --- Harl filter

The final exercise builds a filtering mechanism around Harl's levels.

Instead of executing only one exact complaint, the program chooses a
minimum severity and executes the corresponding level and all more
severe levels.

The implementation therefore introduces:

-   `switch`
-   string-to-level mapping
-   controlled fall-through
-   member-function dispatch

### CPP01 takeaway

After `CPP00`, the mental model changes from:

> "I have variables and classes."

to:

> "I have objects with lifetimes, ownership and relationships."

---

# CPP02 --- Fixed-Point Numbers and Operator Overloading

`CPP02` is where the repository starts treating C++ classes like real
value types.

The central class is:

``` cpp
Fixed
```

---

## ex00 --- Raw fixed-point storage

The class contains:

``` cpp
int _value;
static const int _fractBits = 8;
```

The integer stores the raw fixed-point representation.

The first exercise focuses on:

-   default constructor
-   copy constructor
-   assignment operator
-   destructor
-   raw getter/setter

This establishes the **canonical form** pattern.

---

## ex01 --- Conversions

The class gains:

``` cpp
int toInt() const;
float toFloat() const;
```

The raw representation is converted back to normal numeric values.

The key idea is:

``` text
stored integer
      +
fractional-bit count
      ↓
real numerical value
```

With eight fractional bits, the scale is based on:

``` text
2^8
```

The implementation uses bit shifting and floating-point conversion.

---

## ex02 --- Full value type

The class now supports:

-   integer constructor
-   floating-point constructor
-   comparison operators
-   arithmetic operators
-   increment/decrement
-   `min` / `max`

The implementation turns `Fixed` into a real numeric abstraction.

### Operator overloading

Instead of:

``` cpp
a.add(b)
```

the user can write:

``` cpp
a + b
```

The class therefore behaves like a number while controlling its internal
representation.

### Prefix vs postfix

The two forms:

``` cpp
++a;
a++;
```

have different operator signatures.

The postfix form receives a dummy `int` parameter so C++ can distinguish
it.

### 🎓 What Is Learned

-   canonical class form
-   fixed-point representation
-   bit operations
-   conversions
-   operator overloading
-   const correctness
-   value semantics

---

# CPP03 --- Inheritance

`CPP03` introduces class hierarchies.

The base class is:

``` text
ClapTrap
```

Then:

``` text
        ClapTrap
           |
       ScavTrap
```

and later:

``` text
        ClapTrap
        /      \
   ScavTrap   FragTrap
```

---

## ex00 --- ClapTrap

`ClapTrap` contains state such as:

-   name
-   hit points
-   energy points
-   attack damage

It implements:

``` cpp
attack()
takeDamage()
beRepaired()
```

The implementation checks whether the object still has resources before
performing actions.

### 🏗️ Important Design Idea

The class is not just a collection of functions. Its functions maintain
invariants on internal state.

For example:

``` text
no hit points → cannot continue normally
no energy → cannot perform energy-consuming actions
```

---

## ex01 --- ScavTrap

`ScavTrap` derives from `ClapTrap`.

It changes its own initial statistics and adds:

``` cpp
guardGate()
```

The derived class explicitly calls the base-class constructor in its
initializer list.

This demonstrates constructor chaining:

``` text
ScavTrap constructor
       ↓
ClapTrap constructor
       ↓
ScavTrap body
```

---

## ex02 --- FragTrap

`FragTrap` adds:

``` cpp
highFivesGuys()
```

Now the hierarchy contains two different derived types.

The main program also exercises copying:

``` cpp
FragTrap kimJongUnTmp(kimJongUn);
```

which reinforces copy construction in an inheritance context.

### 🎓 What Is Learned

-   base/derived relationship
-   inheritance
-   constructor chaining
-   inherited state
-   overriding/redefining behavior
-   multiple derived classes
-   object copying

---

# CPP04 --- Polymorphism, Abstract Classes and Interfaces

`CPP04` is the major object-oriented C++ module.

The central hierarchy is:

``` text
        Animal
        /    \
      Dog    Cat
```

with separate `WrongAnimal` / `WrongCat` classes used to demonstrate
what happens without proper virtual dispatch.

---

## ex00 --- Runtime polymorphism

`Animal::makeSound()` is virtual.

`Dog::makeSound()` and `Cat::makeSound()` provide specialized behavior.

When an object is accessed through an `Animal*`, the virtual function
allows the correct derived implementation to execute.

This is **runtime polymorphism**.

### ❓ Why WrongAnimal Exists

The `WrongAnimal` hierarchy intentionally lacks the same virtual
behavior.

It demonstrates that inheritance alone does not automatically mean
polymorphism.

The crucial mechanism is the virtual function.

---

## ex01 --- Deep copy with Brain

A `Brain` object is added to `Dog` and `Cat`.

Each animal owns its own brain dynamically.

This introduces a real ownership problem.

A shallow copy would copy only the pointer:

``` text
Animal A ──> Brain X
Animal B ──> Brain X
```

That means both animals share the same brain.

A deep copy instead creates:

``` text
Animal A ──> Brain X
Animal B ──> Brain Y
```

The implementation therefore requires correct copy construction and
assignment.

### 🧠 Main Lesson

When a class owns dynamic memory, the canonical form is not enough
conceptually; the copy operations must preserve ownership correctly.

---

## ex02 --- Abstract Animal

`Animal::makeSound()` becomes pure virtual:

``` cpp
virtual void makeSound() const = 0;
```

This makes `Animal` abstract.

An abstract class is used as an interface/base contract rather than
instantiated directly.

The hierarchy becomes:

``` text
            Animal
           /      \
         Dog      Cat
```

where `Animal` specifies what derived classes must provide.

### CPP04 takeaway

This module connects:

``` text
inheritance
   ↓
virtual functions
   ↓
runtime polymorphism
   ↓
abstract classes
   ↓
dynamic ownership and deep copying
```

---

# CPP05 --- Exceptions and Bureaucratic Forms

`CPP05` turns validation into a structured exception-based system.

The main class is:

``` text
Bureaucrat
```

with grades constrained between 1 and 150.

The important conceptual rule is:

``` text
1 = highest
150 = lowest
```

---

## ex00 --- Bureaucrat

The constructor validates the grade.

Invalid values throw:

``` text
GradeTooHighException
GradeTooLowException
```

The class also provides:

``` cpp
incrementGrade()
decrementGrade()
```

These operations must respect the grade limits.

### 🎓 What Is Learned

Exceptions separate:

``` text
normal execution
```

from:

``` text
exceptional invalid state
```

Instead of returning an error code from every operation, the object
throws an exception when its invariant would be violated.

---

## ex01 --- Form

`Form` introduces a second object with its own grade requirements.

A form has:

-   name
-   signed state
-   grade required to sign
-   grade required to execute

The bureaucrat can sign it only if the bureaucrat's grade is
sufficiently high.

This creates an interaction:

``` text
Bureaucrat
    |
    +---- signs ----> Form
```

---

## ex02 --- AForm and concrete forms

`AForm` becomes an abstract base class.

Concrete forms include:

``` text
ShrubberyCreationForm
RobotomyRequestForm
PresidentialPardonForm
```

Each concrete form implements:

``` cpp
_executeAction()
```

with different behavior.

### Shrubbery

Creates a file:

``` text
<target>_shrubbery
```

and writes tree-like ASCII content.

### Robotomy

Prints the robotomy behavior and uses randomness to determine the
result.

### Presidential pardon

Prints the pardon result.

The common interface lives in `AForm`, while the specific action belongs
to the derived form.

---

## ex03 --- Intern

The final step adds an `Intern`.

Instead of manually constructing the correct form everywhere, the intern
receives a form name and creates the appropriate concrete form.

Conceptually:

``` text
"shrubbery creation"
        ↓
ShrubberyCreationForm

"robotomy request"
        ↓
RobotomyRequestForm

"presidential pardon"
        ↓
PresidentialPardonForm
```

### CPP05 takeaway

The module combines:

-   invariants
-   exceptions
-   encapsulation
-   abstract classes
-   polymorphism
-   factory-like object creation

---

# CPP06 --- C++ Casts

This module isolates the three major cast families used by the
repository.

---

## ex00 --- `static_cast`

`ScalarConverter` receives a string and determines whether it
represents:

-   char
-   int
-   float
-   double
-   pseudo-literal

The implementation first detects the type and then dispatches to display
functions:

``` text
detectType()
     |
     +--> displayChar()
     +--> displayInt()
     +--> displayFloat()
     +--> displayDouble()
     +--> displayPseudo()
```

The goal is to convert between scalar representations.

### 📌 Important Lesson

`static_cast` is appropriate for compile-time-known scalar conversions
where the conversion is structurally valid.

---

## ex01 --- `reinterpret_cast`

`Serializer` converts a pointer into an integer representation:

``` cpp
uintptr_t
```

and then converts it back.

Conceptually:

``` text
Data*
  ↓
uintptr_t
  ↓
Data*
```

The important point is that the object's data is not copied. The address
representation is transformed.

---

## ex02 --- `dynamic_cast`

The repository creates a polymorphic `Base` hierarchy:

``` text
       Base
      / | \
     A  B  C
```

The implementation provides two identification functions:

``` cpp
identify(Base *p);
identify(Base &p);
```

The pointer version checks failed casts against `NULL`.

The reference version catches `std::bad_cast`.

This clearly demonstrates the difference between pointer and reference
behavior with `dynamic_cast`.

### CPP06 takeaway

The casts are not interchangeable:

``` text
static_cast
    → known compile-time conversion

reinterpret_cast
    → low-level representation/address conversion

dynamic_cast
    → runtime polymorphic type identification
```

---

# CPP07 --- Templates

`CPP07` introduces generic programming.

The key idea is:

> Write the algorithm once and let the type be supplied later.

---

## ex00 --- `whatever`

The `swap()` function is templated:

``` cpp
template <typename T>
void swap(T &a, T &b);
```

The same implementation works for:

``` text
int
string
...
```

as long as the type supports the operations required by the function.

---

## ex01 --- `iter`

`iter()` receives:

-   an array
-   its length
-   a function pointer

It applies the supplied function to every element.

Two overloads exist:

``` cpp
T *arr
```

and:

``` cpp
const T *arr
```

This preserves const correctness.

The demonstration functions include printing, incrementing integers and
converting strings to uppercase.

---

## ex02 --- Array

`Array<T>` is a templated class implementing a dynamic array
abstraction.

The repository includes:

``` text
Array.hpp
Array.tpp
```

The class provides:

-   constructors
-   copy construction
-   assignment
-   indexing
-   `size()`
-   bounds checking
-   const access

The `.tpp` file contains template implementation details.

### 📌 Important Lesson

Templates are normally implemented in headers because the compiler needs
to see the implementation when instantiating a template.

### CPP07 takeaway

The abstraction moves from:

``` text
class works for one type
```

to:

``` text
algorithm/data structure works for many types
```

---

# CPP08 --- STL Containers and Algorithms

`CPP08` begins practical use of the Standard Template Library.

---

## ex00 --- easyfind

The function is templated:

``` cpp
easyfind(T &c, int i)
```

and searches a container for a value.

The implementation uses the container's iterators.

There is also a const overload.

Conceptually:

``` text
container
   ↓
begin() ... end()
   ↓
search for value
   ↓
iterator or failure
```

### 🎓 Lesson

Generic algorithms do not need to know the concrete container type as
long as the container exposes the expected iterator interface.

---

## ex01 --- Span

`Span` stores integers up to a fixed capacity.

It supports:

``` cpp
addNumber()
shortestSpan()
longestSpan()
```

It also has a templated:

``` cpp
addNumbers(first, last)
```

which inserts a whole iterator range.

### Shortest span

The implementation copies the data, sorts it, then compares adjacent
values.

For sorted values:

``` text
1 4 7 20
```

the smallest difference must occur between two neighboring elements.

So:

``` text
min(
  4 - 1,
  7 - 4,
  20 - 7
)
```

is enough.

### Longest span

The maximum is simply:

``` text
max element - min element
```

### 🎓 Lesson

This exercise combines:

-   STL containers
-   iterators
-   algorithms
-   sorting
-   range insertion
-   complexity considerations

---

## ex02 --- MutantStack

The repository extends stack behavior by exposing:

``` cpp
begin()
end()
```

while still behaving like a stack.

The important point is that `std::stack` is an adaptor rather than a
normal iterable container.

The custom class exposes iterators through its underlying container.

### CPP08 takeaway

The focus changes from:

> "How do I implement a data structure?"

to:

> "How do I use and extend the STL correctly?"

---

# CPP09 --- STL, Parsing and Algorithms

`CPP09` is the most application-oriented module in the repository.

It contains three distinct problems:

``` text
ex00 → Bitcoin exchange
ex01 → Reverse Polish Notation
ex02 → PmergeMe / Ford-Johnson
```

---

## CPP09/ex00 --- BitcoinExchange

The program reads exchange-rate data from:

``` text
data.csv
```

and processes another input file.

The class validates:

-   dates
-   leap years
-   rates
-   values

It then retrieves the appropriate exchange rate.

### Date validation

The implementation has a dedicated:

``` cpp
isLeapYear()
```

which is necessary because February has different limits depending on
the year.

Then:

``` cpp
isValidDate()
```

checks the date structure and actual calendar validity.

### Exchange lookup

`getExchangeRate()` searches the stored exchange-rate mapping and
chooses the appropriate rate for the requested date.

### 🎓 Lesson

This exercise is about more than containers:

-   parsing text
-   validating structured input
-   date rules
-   numeric validation
-   lookup behavior
-   exception/error handling

---

## CPP09/ex01 --- Reverse Polish Notation

RPN evaluates expressions where the operator appears after its operands.

Example:

``` text
3 4 + 
```

means:

``` text
3 + 4
```

The implementation tokenizes the expression with:

``` cpp
std::stringstream
```

and classifies tokens as either:

``` text
number
operator
```

Operators are applied using a stack-like evaluation model.

### ⚙️ Algorithm

For every token:

``` text
number
    → push it

operator
    → pop right operand
    → pop left operand
    → apply operator
    → push result
```

At the end, one result should remain.

### 🎓 Lesson

This is a direct example of how a simple data structure can express an
algorithm cleanly.

---

## CPP09/ex02 --- PmergeMe / Ford-Johnson / Merge-Insertion Sort

This is the most algorithmically interesting exercise in the repository.

The implementation does **not** simply call `std::sort()`.

Instead, it implements a Ford-Johnson-style merge-insertion sort for:

``` text
std::vector<int>
std::deque<int>
```

and compares their processing times.

---

### What the program does

Input:

``` text
./PmergeMe 5 9 2 8 1 7
```

Conceptually:

``` text
Before: 5 9 2 8 1 7
After:  1 2 5 7 8 9
```

Then it reports the measured processing time for:

``` text
std::vector
std::deque
```

---

## CPP09/ex02 --- Core Data Design

The class stores:

``` cpp
std::vector<int> _input;
std::vector<int> _vector;
std::deque<int> _deque;

std::vector<int> _sortedVector;
std::deque<int> _sortedDeque;

double _vectorTime;
double _dequeTime;
```

The interesting implementation choice is that the sorting recursion
operates on **indices**, not directly on values.

That is why there are:

``` cpp
std::vector<std::size_t>
std::deque<std::size_t>
```

index sequences.

This avoids repeatedly moving the original values during the recursive
pairing stage.

---

## Step 1 --- Validate the input

The constructor loops through:

``` cpp
argv[1] ... argv[argc - 1]
```

and calls:

``` cpp
isDigits()
addNum()
```

### `isDigits()`

It rejects:

-   empty strings
-   negative signs
-   decimal points
-   alphabetic characters
-   any character outside `'0'` to `'9'`

So the accepted input format is a positive decimal integer.

### `addNum()`

The string is parsed with:

``` cpp
std::stringstream
```

Then it rejects:

``` text
conversion failure
remaining characters
values <= 0
```

Only valid integers are pushed into `_input`.

---

## Step 2 --- Create index sequence

For vector sorting:

``` text
0 1 2 3 4 5 ...
```

is created.

For example:

``` text
values = [9, 3, 7, 2]

indices = [0, 1, 2, 3]
```

The algorithm sorts the indices according to the values they refer to.

At the end:

``` text
sorted indices = [3, 1, 2, 0]
```

can produce:

``` text
[2, 3, 7, 9]
```

This is the key design idea behind the implementation.

---

## Step 3 --- Pair the elements

`VectorPairs` receives the current index sequence.

It processes two indices at a time:

``` text
(a, b)
```

and compares:

``` cpp
_vector[a]
_vector[b]
```

The larger index is stored in:

``` cpp
largeIdx
```

and the smaller one is recorded as its partner.

So a pair such as:

``` text
(9, 3)
```

becomes conceptually:

``` text
large = 9
small  = 3
```

The algorithm does not lose the relationship between them.

That relationship is required later when the smaller element is
inserted.

---

## Step 4 --- Handle an odd element

If the number of elements is odd, one element cannot form a pair.

The implementation stores it in:

``` cpp
VectorStraggler
```

with:

``` cpp
has
id
```

The same idea exists for `deque`.

This element is postponed until the main insertion process is complete.

---

## Step 5 --- Recursively sort the larger elements

After pairing, only the larger member of each pair is kept in the
recursive sequence.

Example:

``` text
pairs:

(9, 3)
(8, 2)
(7, 1)
```

The recursive sequence is:

``` text
9 8 7
```

The function:

``` cpp
fordJohnsonSortVectorIdx()
```

recursively sorts those larger elements.

The important reduction is:

``` text
N elements
   ↓ pair
about N/2 larger elements
   ↓ recursively sort
sorted main chain
```

---

## Step 6 --- Build the main chain

After recursion:

``` cpp
idx.clear();
```

and the sorted larger indices are inserted back.

The resulting sequence is the beginning of the **main chain**.

At this point, the larger elements are ordered.

But the smaller partners still need to be inserted.

---

## Step 7 --- Why binary insertion is used

The smaller partner of a pair is known to be smaller than its larger
partner.

If:

``` text
small < large
```

and `large` is already inside the sorted main chain, there is no reason
to search beyond that partner.

The implementation stores the position of each large element in:

``` cpp
largePos
```

Then it calls:

``` cpp
vector_lower_bound()
```

or:

``` cpp
deque_lower_bound()
```

This is a binary search.

The search range is:

``` text
[begin, end)
```

and the midpoint is calculated with:

``` cpp
mid = begin + (last - begin) / 2;
```

This avoids overflow-prone midpoint formulas.

The comparison:

``` cpp
_vector[mainChain[mid]] >= value
```

moves the search toward the first valid insertion position.

So the smaller partner is inserted into the smallest possible search
range.

---

## Step 8 --- Jacobsthal numbers determine insertion order

This is the defining optimization in the implementation.

The function:

``` cpp
vectorJacobsthalOrder()
```

builds the Jacobsthal sequence using:

``` text
J(n) = J(n-1) + 2 * J(n-2)
```

starting from:

``` text
J(0) = 0
J(1) = 1
```

The generated values control the order in which pending elements are
inserted.

The code then walks backward between consecutive Jacobsthal boundaries:

``` cpp
for (...)
    for (j = min(J[i], size); j > J[i - 1]; --j)
        order.push_back(j);
```

This gives the insertion order used by:

``` cpp
insertVectorPend()
```

and its deque equivalent.

### Why this matters

The algorithm is not simply:

``` text
insert small 1
insert small 2
insert small 3
...
```

Instead, it chooses a carefully constructed order that keeps the
binary-search ranges favorable and reduces the number of comparisons.

That is the reason Jacobsthal numbers appear in Ford-Johnson /
merge-insertion sort.

---

## Step 9 --- Insert pending elements

`insertVectorPend()` is one of the most important functions in the whole
repository.

For every ID in the Jacobsthal insertion order:

1.  Find the corresponding large element.
2.  Find its smaller partner.
3.  Determine the current position of the large element.
4.  Search only before that position.
5.  Insert the smaller partner.
6.  Update every affected large-element position.

The critical relationship is:

``` text
small partner
      ↓
must be inserted before
      ↓
its associated large partner
```

The code preserves that relationship through `pairs.partner`.

---

## Step 10 --- Insert the straggler

If the original number of elements was odd, the final unpaired element
is inserted after the pending pairs.

The implementation calls:

``` cpp
insertVectorStraggler()
```

It performs a binary search over the entire main chain because there is
no paired large element that gives it a natural upper bound.

---

## Step 11 --- Convert sorted indices back to values

The algorithm has sorted:

``` text
indices
```

rather than the actual value container.

The final pass creates:

``` cpp
_sortedVector
```

with:

``` cpp
_sortedVector.push_back(_vector[idx[i]]);
```

The same design is repeated for `deque`.

---

## Vector and Deque Implementations

The repository intentionally implements both versions.

The vector side contains:

``` text
VectorPairs
VectorStraggler
vectorJacobsthalOrder
vector_lower_bound
insertVectorPend
insertVectorStraggler
fordJohnsonSortVectorIdx
fordJohnsonSortVector
processVector
```

The deque side mirrors the same algorithm:

``` text
DequePairs
DequeStraggler
dequeJacobsthalOrder
deque_lower_bound
insertDequePend
insertDequeStraggler
fordJohnsonSortDequeIdx
fordJohnsonSortDeque
processDeque
```

This makes the comparison much cleaner because the algorithm itself is
essentially the same while the underlying container changes.

---

## CPP09/ex02 --- Algorithm in One Picture

``` text
Input
  |
  v
Validate positive integers
  |
  v
Create index sequence
  |
  v
Pair elements
  |
  +---- odd element? ---> save straggler
  |
  v
Keep larger element of every pair
  |
  v
Recursively Ford-Johnson sort larger elements
  |
  v
Build sorted main chain
  |
  v
Generate Jacobsthal insertion order
  |
  v
Insert smaller partners using binary search
  |
  v
Insert straggler
  |
  v
Convert sorted indices back to values
  |
  v
Sorted result
```

---

## CPP09/ex02 --- Small Conceptual Example

Suppose the input is:

``` text
9 3 8 2 7
```

Pairing gives:

``` text
(9, 3)
(8, 2)
```

and one straggler:

``` text
7
```

The larger elements are:

``` text
9 8
```

Their partners are:

``` text
9 -> 3
8 -> 2
```

The recursive phase sorts:

``` text
9 8
```

into:

``` text
8 9
```

The main chain starts with:

``` text
8 9
```

Then the smaller partners are inserted using the Jacobsthal order and
binary search:

``` text
3
2
```

Finally:

``` text
7
```

is inserted as the straggler.

The important point is that the algorithm does not randomly insert
values. Every insertion uses information already established by the pair
comparison.

---

## CPP09/ex02 --- Complexity Intuition

Ford-Johnson is designed around minimizing comparisons.

The implementation combines:

-   pair comparisons
-   recursive sorting of the larger elements
-   bounded binary insertion
-   Jacobsthal-based insertion order

The implementation therefore demonstrates an important algorithmic idea:

> Complexity is not only about which data structure is used. The order
> in which comparisons are made can also matter.

The repository then measures the actual runtime for both containers
using:

``` cpp
std::clock()
```

and converts clock ticks to microseconds.

The measured result is reported separately for:

``` text
std::vector
std::deque
```

---

# 🛠️ Building an Exercise

Move into the directory of the exercise you want to compile:

```bash
cd CPP09/ex02
make
```

Then run the generated executable:

```bash
./PmergeMe 3 5 9 7 4 2 8 1 6
```

The executable name is defined by the corresponding `Makefile`.

### Available Make targets

```bash
make
make clean
make fclean
make re
```

Their purpose is:

| Target | Action |
|---|---|
| `make` | Compile the exercise |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and executable |
| `make re` | Full clean rebuild |

---

# ⛓️‍💥 C++98 Constraints

The modules are intentionally written in **C++98**.

The code therefore avoids modern C++ features such as:

```text
auto
nullptr
range-based for
lambdas
std::to_string
```

The exercises instead rely on the C++98 toolbox:

- `std::string`;
- references and pointers;
- manual dynamic allocation;
- constructors / destructors;
- inheritance;
- virtual functions;
- exceptions;
- RTTI;
- templates;
- STL containers and iterators.

---

# 🧩 Design Principles Practiced

Across the repository, the implementations repeatedly apply:

### 💊 Encapsulation

State is kept private or protected and exposed through controlled member functions.

### 🌱 Object Lifetime

Heap allocations are paired with the appropriate cleanup:

```text
new    → delete
new[]  → delete[]
```

### 🏛️ Orthodox Canonical Form

Several classes implement the standard special member functions:

```text
default constructor
copy constructor
copy assignment operator
destructor
```

### 💾 Deep Copy

Classes owning dynamic resources, such as `Cat` / `Dog` and `Array<T>`, allocate independent copies instead of sharing the same memory.

### 🎭 Runtime Polymorphism

The later modules use virtual functions, abstract classes, and `dynamic_cast` to work with objects through base-class interfaces.

### ⚙️ Generic Programming

Templates are used to remove type-specific duplication while preserving type safety.

### 📦 STL

The final modules use standard containers and algorithms rather than rebuilding every data structure from scratch.

### 🔍 Validation & Error Handling

Parsing-heavy exercises validate input before operating on it and use exceptions for invalid states and failures.

---

# 📌 Exercise Specifications

Each module contains its corresponding subject PDF:

- [`CPP00 subject`](CPP00/en.subject.pdf)
- [`CPP01 subject`](CPP01/en.subject.pdf)
- [`CPP02 subject`](CPP02/en.subject.pdf)
- [`CPP03 subject`](CPP03/en.subject.pdf)
- [`CPP04 subject`](CPP04/en.subject.pdf)
- [`CPP05 subject`](CPP05/en.subject.pdf)
- [`CPP06 subject`](CPP06/en.subject.pdf)
- [`CPP07 subject`](CPP07/en.subject.pdf)
- [`CPP08 subject`](CPP08/en.subject.pdf)
- [`CPP09 subject`](CPP09/en.subject.pdf)

The subject files define the original exercise requirements; this README documents the implementation present in this repository.

---

# 👤 Author

**Zakaria Talbi**

- GitHub: [@zakariatalbii](https://github.com/zakariatalbii)

---

# 📜 License

This project is part of the 42 School cursus.
