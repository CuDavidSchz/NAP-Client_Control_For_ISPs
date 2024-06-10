# NAP - Client control for ISPs

The following project is about a program focused on managing a fiber optic network using object-oriented programming, including the concepts of inheritance and its methods.

The problem arises when searching the Internet I did not find a program that could manage an FFTH network efficiently and easily. Although there were solutions that seemed to solve separate parts of the problem. This program, limited by the author's knowledge, is an approach to what could be a much more complex program to solve this problem. In the future, resolve the bugs it presents, add databases, user profiles and graphical interface.


In the logic of a fiber optic network, there are several objects that fall into common categories. For example, there are elements that form the backbone of the network such as racks (where electronic components and cables are stored), splice closures (which distribute the optical signal to the terminals) and finally network access points. NAP.

In this project these three elements were grouped to create the "Network Element" superclass that stores all the common characteristics and methods that these objects have. But, although they are part of the backbone, they do not work the same, which is why virtual methods are included to be able to handle them correctly in each subclass.

The relationship that objects have is one of aggregation, since they can exist without the existence of the other. For example, a rack can live without closures, NAPs and clients. The same thing happens for the others, but if they are not added to others it loses its meaning.

When clients are created, they must be connected to a network access point, this must be connected to a splice closure so that it receives an optical signal and finally the splice must be connected to a rack.
