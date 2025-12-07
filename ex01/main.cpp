#include <stdint.h>
#include <stdio.h>
#include <iostream>
#include <cstdint>

// int main() {
// //     int value = 10;
// //     int *ptr = &value;

// //     // Convert pointer to uintptr_t
// //     uintptr_t int_ptr = (uintptr_t)ptr;

// //     printf("Original pointer: %p\n", (void*)ptr);
// //     printf("Integer representation of pointer: 0x% \n", int_ptr); // PRIXPTR for printing uintptr_t

// //     // Convert back to pointer
// //     int* restored_ptr = (int*)int_ptr;

// //     printf("Restored pointer: %p\n", (void*)restored_ptr);
// //     printf("Value through restored pointer: %d\n", *restored_ptr);

// //     return 0;


//     // unsigned long p = 0x7ffeefbff5a0; // 140732919274656

//     // printf("Hexadecimal: %lx\n", 0x7ffeefbff5a0ul);


//     // printf("Hexadecimal ---> unsigned long: %lu\n", (unsigned long )0x7ffeefbff5a0);

//     // printf("decimal -----> Hexadecimal: %lx\n", (unsigned long)140732920755616);

//     // std::cout << sizeof(uintptr_t) << std::endl;






//     // int x = 10;
//     // int *ptr = &x ;
//     // uintptr_t raw;


//     // raw = reinterpret_cast<uintptr_t>(ptr);


//     // std::cout << "raw: " << raw << "\nsizeof(raw): " <<  sizeof(raw) << std::endl;


//     // std::cout << "ptr: " << ptr << "\n";

//     // uintptr_t raw = 0x7ffeefbff5a0;

//     // std::cout << std::hex << raw << "\n";       // print hex
//     // std::cout << std::dec << raw << "\n";       // print decimal
//     // std::cout << std::hex << raw << "\n";       // print hex


// }

/**************************************************************************************************** */


// #include <iostream>
// #include <cstdint>
// #include <iomanip>

// int main() {
//     int x = 42;
//     int* ptr = &x; // 1. Pointer holds the memory address of x

//     // 2. reinterpret_cast: Treat the bits of 'ptr' as a uintptr_t integer
//     uintptr_t address_as_int = reinterpret_cast<unsigned int>(ptr);

//     std::cout << "address_as_int: " << address_as_int << "\n";

//     std::cout << "Pointer Address (Hex): 0x" 
//               << std::hex << address_as_int << std::endl;

//     std::cout << "Address Value (Decimal): " 
//               << std::dec << address_as_int << std::endl;

//     // 3. uintptr_t: The integer type holds the numerical value of the address
    
//     return 0;
// }



#include "Serializer.hpp"

int main()
{
    // Create Data object
    Data d;
    d.id = 42;
    d.name = "Hello";

    // Pointer to that object
    Data* ptr = &d;

    // Serialize (pointer → integer)
    uintptr_t raw = Serializer::serialize(ptr);

    // Deserialize (integer → pointer)
    Data* restored = Serializer::deserialize(raw);

    // Show everything
    std::cout << "Original pointer : " << ptr << "\n";
    std::cout << "Serialized (raw) : " << raw << "\n";
    std::cout << "Restored pointer : " << restored << "\n\n";

    std::cout << "Restored Data:\n";
    std::cout << "  number = " << restored->id << "\n";
    std::cout << "  text   = " << restored->name << "\n";

    return 0;
}
