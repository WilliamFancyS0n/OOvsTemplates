Based on the results of my tests, it is apparent that templates run a significant amount faster.
My tests stress vectors containing 50000 objects of type ICStringWrapper, ICIntWrapper, StringWrapper, IntWrapper.

ICStringWrapper, ICIntWrapper are sorted using inheritance techniques, while StringWrapper, IntWrapper are sorted using templates.


