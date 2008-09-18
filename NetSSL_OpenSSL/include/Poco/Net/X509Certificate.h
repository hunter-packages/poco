//
// X509Certificate.h
//
// $Id: //poco/1.3/NetSSL_OpenSSL/include/Poco/Net/X509Certificate.h#3 $
//
// Library: NetSSL_OpenSSL
// Package: SSLCore
// Module:  X509Certificate
//
// Definition of the X509Certificate class.
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef NetSSL_X509Certificate_INCLUDED
#define NetSSL_X509Certificate_INCLUDED


#include "Poco/Net/NetSSL.h"
#include "Poco/Net/Context.h"
#include "Poco/SharedPtr.h"
#include <openssl/ssl.h>


namespace Poco {
namespace Net {


class NetSSL_API X509Certificate
	/// This class represents an X509 Certificate.
{
public:
	X509Certificate(const std::string& file);
		/// Loads the X509Certificate from the file

	X509Certificate(X509* pCert);
		/// Creates the X509Certificate.

	X509Certificate(const X509Certificate&);

	X509Certificate& operator=(const X509Certificate&);

	void swap(X509Certificate& cert);

	~X509Certificate();
		/// Destroys the X509Certificate.

	const std::string& issuerName() const;
		/// Returns the certificate issuer name.
		
	const std::string& subjectName() const;
		/// Returns the certificate subject name.
		
	const X509* certificate() const;
		/// Returns the OpenSSL certificate.

	bool verify(const std::string& hostName, Poco::SharedPtr<Context> ptr);
		/// Verifies the validity of the certificate against the hostname.
		
private:
	void initialize();
		/// Extracts data from _pCert. Assumes _pCert != 0.

private:
	std::string _issuerName;
	std::string _subjectName;
	X509*       _pCert;
	std::string _file;
};


//
// inlines
//
inline const std::string& X509Certificate::issuerName() const
{
	return _issuerName;
}


inline const std::string& X509Certificate::subjectName() const
{
	return _subjectName;
}


inline const X509* X509Certificate::certificate() const
{
	return _pCert;
}


} } // namespace Poco::Net


#endif // NetSSL_X509Certificate_INCLUDED
