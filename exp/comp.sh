#!/bin/bash
#GLIB_LIBS = -lgio-2.0 -lgobject-2.0 -lglib-2.0 
#GTKDOC_DEPS_LIBS = -lgobject-2.0 -lglib-2.0 
#INTROSPECTION_LIBS = -lgirepository-1.0 -lgobject-2.0 -lglib-2.0 
#KRB5_LIBS = -lgssapi_krb5 -lkrb5 -lk5crypto -lcom_err
#SQLITE_LIBS = -lsqlite3 
#XML_LIBS = -lxml2 
F=test; g++ $F.c -I/usr/include/libsoup-2.4 -I/usr/include/glib-2.0 -I/usr/lib64/glib-2.0/include -I/usr/include/json-glib-1.0 -lgobject-2.0 -lglib-2.0 -lgio-2.0 -ljson-glib-1.0 -lsoup-2.4 -lgirepository-1.0 -lgssapi_krb5 -lkrb5 -lk5crypto -lsqlite3 -lxml2 -o$F >fehler 2>&1 \
  &&{ ./$F;:;} \
  ||vim +2 fehler
