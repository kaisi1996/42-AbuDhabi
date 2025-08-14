#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstdlib>


template <typename T>

// classes

class Array
{
	private:
		T				*array;
		unsigned int	size_;

	public:
	// Constructors
		Array(): size_(0)
		{
			std::cout << "Default Constructor called" << std::endl;
			this->array = new T[this->size_];
		}

		Array(unsigned int size): size_(size)
		{
			std::cout << "Constructor for an Array of size " << size_ << " called" << std::endl;
			this->array = new T[this->size_];
			// for (unsigned int i = 0; i < this->size; i++)
			// 	std::cout << this->_array[i] << std::endl;
		}

		Array(const Array &other): size_(other.size_)
		{
			std::cout << "Copy Constuctor called" << std::endl;
			this->size_ = other.size_;
			this->array = new T[this->size_];
			for (unsigned int i = 0; i < this->size_; i++)
				this->array[i] = other.array[i];
		}

	// Deconstructors
		~Array()
		{
			if (this->array != NULL)
				delete [] this->array;
		}

	// Overloaded Operators
		Array &operator=(const Array &other)
		{
			if (this->array != NULL)
				delete [] this->array;
			if (other.size_ != 0)
			{
				this->size_ = other.size_;
				this->array = new T[this->size_];
				for (unsigned int i = 0; i < this->size_; i++)
					this->array[i] = other.array[i];
			}
			return (*this);
		}

		T &operator[]( unsigned int index )
		{
			if (index >= this->size_ || this->array == NULL)
			{
				std::cout << "index: " << index << std::endl;
				throw Array<T>::InvalidIndexException();
			}
			return (this->array[index]);
		}

	// Exception

		class	InvalidIndexException : public std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("Error: Invalid index");
				}
		};
	// Public Methods

	// Getter
		unsigned int size() const
		{
			return (this->size);
		}

};


#endif