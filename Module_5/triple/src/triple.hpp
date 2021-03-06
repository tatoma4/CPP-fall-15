#ifndef ELEC_CPP_TRIPLES_HH
#define ELEC_CPP_TRIPLES_HH
#include <typeinfo>
/* Add include guards here */

/* Class: Triple
 * -------------
 * The template class Triple is a container class, which holds three values.
 * All of the values can be of different type. All of the values should be
 * private.
 *
 * The constructor of the class takes three const references to values as a
 * parameter. The parameters are in order, in other words, after construction
 * the first parameter should be accessible through the public member function
 * first, the second parameter through the public member function, second, and
 * the third through the public member function third. 
 *
 * The default empty constructor should also work.
 *
 * The Triple class should also support the copy constructor, and assignment
 * operations.
 */
 template<typename T1, typename T2, typename T3>
 class Triple {
 public:

 	Triple(const T1 &first, const T2 &second, const T3 &third) : f(first), s(second), t(third) {}

 	/* Public member functions:
 * ------------------------
 * The triple class has three public member functions, which are used to
 * access the stored elements.
 *
 * Function: first
 * The function takes no parameters.
 * The function returns a const reference to the first value of the triple.
 *
 * Function: second
 * The function takes no parameters.
 * The function returns a const reference to the second value of the triple.
 *
 * Function: third
 * The function takes no parameters.
 * The function returns a const reference to the third value of the triple.
 */
 	
 	const T1& first() const {
 		return f;
 	}
 	
 	
 	const T2& second() const {
 		return s;
 	}

 	
 	const T3& third() const {
 		return t;
 	}

 	/* Operator overloads:
 * -------------------
 * The triple class should support the following operators:
 *
 * Assignment operator, =
 * The default functionality should do here.
 *
 * Equality operator, ==
 * You can assume that all the values in the triple can be compared by the
 * == -operator. Two triples are equal if the corresponding values in both
 * of the triples are equal.
 *
 * Inequality operator, !=
 * You can assume that all the values in the triple can be compared by the
 * != -operator. Two triples are inequal if even one corresponding value in
 * the triples is different.
 *
 * The output stream operator, <<
 * You can assume that all the values in the triple support the << -operator.
 * The triple should be printed to the output stream in the following format: 
 *
 * [<first value>, <second value>, <third value>]
 *
 * Note that there is NO new line at the end of the output.
 *
 */
 

private:
	T1 f;
	T2 s;
	T3 t;
 };


/* Non-member functions:
 * ---------------------
 * Function: isHomogenous
 * The function is a non-member function that takes a triple as a parameter.
 * The function returns a boolean value indicating whether the triple is
 * homogenous or not. A triple is homogenous if all of its three values are of
 * the same type.
 *
 * Hint: specialisation can help you here.
 *
 * Function: makeTriple
 * The function is a non-member function that takes three arbitrary type values
 * (note: values, not references) as a parameter and returns a triple created
 * from those three values.
 */
 
/*
template<typename T>
 bool isHomogenous(const Triple<T, T, T>) {

 }
works in compile time as typeid works in runtime

*/ 


template<typename T1, typename T2, typename T3>
bool isHomogenous(const Triple<T1, T2, T3> t){
	if(typeid(t.first()) == typeid(t.second()) && typeid(t.second()) == typeid(t.third())) {
		return true;
	} else {
		return false;
	}
}

template<typename T1, typename T2, typename T3>
Triple<T1, T2, T3> makeTriple(const T1 first, const T2 second, const T3 third){
	Triple<T1, T2, T3> temp = Triple<T1, T2, T3>(first, second, third);
	return temp;
}

template<typename T1, typename T2, typename T3>
bool operator==(const Triple<T1, T2, T3> &lhs, const Triple<T1, T2, T3> &rhs) {
	return (lhs.first() == rhs.first() &&
			lhs.second() == rhs.second() &&
			lhs.third() == rhs.third());
}

template<typename T1, typename T2, typename T3>
bool operator!=(const Triple<T1, T2, T3> &lhs, const Triple<T1, T2, T3> &rhs) {
	return !(lhs == rhs);
}

template<typename T1, typename T2, typename T3>
std::ostream& operator<<(std::ostream& os, const Triple<T1, T2, T3> t) {
	os << "[" << t.first() << ", " << t.second() << ", " << t.third() << "]";
	return os;
}


/* Remember the endif here to close the header guards */
#endif