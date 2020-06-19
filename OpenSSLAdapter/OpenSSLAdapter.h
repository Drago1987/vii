#ifndef OPENSSL_ADAPTER_H
#define OPENSSL_ADAPTER_H

#include <openssl/x509.h>

class OpenSSLAdapter{

public:
OpenSSLAdapter();
virtual ~OpenSSLAdapter();

X509_NAME* get_subject_name();
void print();

};//class OpenSSLAdapter
#endif//OPENSSL_ADAPTER_H
