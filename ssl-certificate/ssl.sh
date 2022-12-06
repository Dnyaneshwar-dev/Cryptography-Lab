openssl req -passout pass:wcesangli -subj "/C=IN/ST=MH/L=SANGLI/O=WCE/CN=Administrator CA/emailAddress=info@walchandsangli.ac.in" -new > wce.ca.cert.csr

openssl rsa -passin pass:wcesangli -in privkey.pem -out wce.ca.key

openssl x509 -in wce.ca.cert.csr -out wce.ca.cert -req -signkey wce.ca.key -days 365

openssl pkcs12 -passout pass:default -export -nokeys -cacerts -in wce.ca.cert -out wce.ca.cert.p12 -inkey wce.ca.key

openssl req -passout pass:abc -subj "/C=IN/ST=MH/L=SANGLI/O=WCE/CN=Dnyaneshwar Ware/emailAddress=dnyaneshwar.ware@walchandsangli.ac.in" -new > dnyaneshwar.cert.csr

openssl rsa -passin pass:abc -in privkey.pem -out dnyaneshwar.key

openssl x509 -req -in dnyaneshwar.cert.csr -out dnyaneshwar.cert -signkey dnyaneshwar.key -CAkey wce.ca.key -CAcreateserial -days 365 

openssl x509 -in dnyaneshwar.cert -out dnyaneshwar.cert.der -outform DER

openssl pkcs12 -passout pass:default -export -in dnyaneshwar.cert -out dnyaneshwar.cert.p12 -inkey dnyaneshwar.key

openssl x509 inform der -in dnyaneshwar.cert  -text -noout

