TEMPLATE = app
SOURCES = age.cpp
QT += widgets

!exists( age.cpp) {
	error ( "No age.cpp file found")
}