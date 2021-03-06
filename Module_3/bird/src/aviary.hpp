#ifndef AVIARY_HH
#define AVIARY_HH
#include <ostream>
#include <vector>

class Bird; // Forward declaration

// This class must not be copied!

class Aviary {
    public:
        Aviary() {}
        ~Aviary();
        // When a bird is added to the aviary, it's ownership
        // is transferred. When the aviary is destroyed, all
        // the birds are destroyed too.
        //
        // If bird is NULL, std::logic_error is thrown.
        void addBird(Bird *bird);

        // This function calls the speak() method of all
        // birds in the order they were added to the aviary.
        // The first parameter is passed to the speak() method
        // of a bird.
        void speakAll(std::ostream &os) const;

        // Create a new type alias sizeType
        typedef std::vector<Bird>::size_type sizeType; 
        // Returns how many birds there are in the aviary.
        size_t size() const;

        // You must implement at least the indexing operator [].
        // It must work for both const and nonconst aviaries.
        // If the aviary is indexed out of bounds, std::out_of_range is
        // thrown.
        // The return types are const Bird * for the const version and
        // Bird * for the nonconst version.

        // Obviously this class must NOT leak any resources.
        // If somebody tries to copy an instance of this class,
        // the compilation must fail.
        Bird* operator[](int index);
        const Bird* operator[](int index) const;

    private:
        std::vector<Bird*> birds;
};

#endif
