#include <exception>
#include <stdexcept>
#include <sstream>

namespace grain
{
	class IncompatibleSizeException : public std::runtime_error
	{
		public:

			//
			//	Constructor.
			//
			IncompatibleSizeException(std::size_t lhsize, std::size_t rhsize)
				: runtime_error( "incompatible size" ), m_lhsize(lhsize), m_rhsize(rhsize)
			{
			}

		private:
			//
			// Left hand size.
			//
			std::size_t m_lhsize;

			//
			// Left hand size.
			//
			std::size_t m_rhsize;

		public:

			virtual const char* what() const throw()
			{
				std::stringstream cnvt;
				cnvt.str("");
				cnvt << runtime_error::what() << ": " << m_lhsize << " != " << m_rhsize;

				return cnvt.str().c_str();
			}
	};

	class NotImplementedException : public std::logic_error
	{
		public:
			virtual char const * what() const throw() { return "Function not yet implemented."; }
	};
}
