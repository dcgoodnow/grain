/*
 *	Vector.h
 *	Author: Daniel Goodnow
 *
 *	Main vector class used for grain library.
 *
 *	Last Modified: Thu 08 Sep 2016 10:42:26 AM PDT
*/

#pragma once

#include <vector>
#include <stdexcept>
#include <include/IncompatibleSizeException.h>
#include <math.h>

namespace grain
{
	template <class T>
	class Vector
	{
		public:

			//
			//	Constructor.
			//
			Vector();

			//
			// Copy Constructor.
			//
			Vector(const Vector<T> &other);

			//
			//	Constructor with size information.
			//
			Vector(std::size_t size);

			//
			//	Destructor.
			//
			~Vector();

		private:

			//
			//	Number of elements in the vector.
			//
			std::size_t size;

			//
			//	Values of the vector.
			//
			std::vector<T> elements;

		public:

			//
			//	Gets the element at the specified location.
			//
			T at(std::size_t index) const;
			
			//
			//	Sets the element at the specified location.
			//
			void set(std::size_t index, T value);

			//
			//	Dot product.
			//
			T dot(const Vector<T> &rhs) const;

			//
			//	Cross product.
			//
			T cross(const Vector<T> &rhs);

			//
			// Returns the length of the vector.
			//
			T length();

		//////////////////////
		//Operator Overloads//
		//////////////////////
		public:

		   //
		   // Assignment operator.
		   //
		   Vector<T>& operator=(const Vector<T> &other);

			//
			//	Gets/Sets the value at the index;
			//
			T& operator[](std::size_t index);
			const T& operator[](std::size_t index) const;

			//
			//	Scalar multiplication.
			//
			Vector operator*(double scalar);

			template <class U>
			friend Vector<U> operator*(double scalar, const Vector<U> &rhs);

			//
			//	Dot product.
			//
			template<class U>
			friend U operator*(const Vector<U> &lhs, const Vector<U> &rhs);
	};

	template <class T>
	Vector<T>::Vector()
	{
		elements = std::vector<T>();
	}

	template <class T>
	Vector<T>::Vector(const Vector<T> &other)
   {
      size = other.size;
      elements = std::vector<T>(other.elements);
   }

	template <class T>
	Vector<T>::Vector(std::size_t size) :
		elements(size, 0)
	{
		this->size = size;
	}

	template <class T>
	Vector<T>::~Vector()
	{
	}

	template <class T>
	T Vector<T>::at(std::size_t index) const
	{
		if(index < size)
			return elements[index];
		else
			throw std::out_of_range("Index out of range");
	}

	template <class T>
	void Vector<T>::set(std::size_t index, T value)
	{
		if(index < size)
			elements[index] = value;
		else
			throw std::out_of_range("Index out of range");
	}

	template <class T>
	Vector<T>& Vector<T>::operator=(const Vector<T> &other)
   {
      this->size = other.size;
      this->elements = std::vector<T>(other.elements);
      return *this;
   }

	template <class T>
	T& Vector<T>::operator[](std::size_t index)
	{
		if(index < size)
			return elements[index];
		else
			throw std::out_of_range("Index out of range");
	}

	template <class T>
	const T& Vector<T>::operator[](std::size_t index) const
	{
		if(index < size)
			return elements[index];
		else
			throw std::out_of_range("Index out of range");
	}
	

	template <class T>
	T Vector<T>::dot(const Vector<T> &rhs) const
	{
		if(this->size != rhs.size)
			throw IncompatibleSizeException(this->size, rhs.size);

		T result = T(0);
		for(int i = 0; i < this->size; ++i)
		{
			result = result + (elements[i] * rhs.elements[i]);
		}
		return result;
	}

	template <class T>
	T Vector<T>::cross(const Vector<T> &rhs)
	{
		throw NotImplementedException();
	}

	template <class T>
	T Vector<T>::length()
	{
		T sum = T(0);
		for(T element : elements)
		{
			sum += element * element;
		}
		return sqrt(sum);
	}

	template <class T>
	Vector<T> Vector<T>::operator*(double scalar)
	{
	   Vector<T> result(*this);
		for(T& element : result.elements)
		{
			element = element * scalar;
		}
		return result;
	}

	template <class T>
	Vector<T> operator*(double scalar, const Vector<T> &rhs)
	{
	   Vector<T> result(rhs);
		for(T& element : result.elements)
		{
			element = element * scalar;
		}
		return result;
	}

	template <class T>
	T operator*(const Vector<T> &lhs, const Vector<T> &rhs)
	{
		return lhs.dot(rhs);
	}
}
