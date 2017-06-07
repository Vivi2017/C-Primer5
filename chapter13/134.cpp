Assuming Point is a class type with a public copy constructor, identify each use of the copy constructor in this program fragment:

Point global;
Point foo_bar(Point arg) // 1 non-refrence parameter
{
    Point local = arg;// 2 use =
    Point *heap = new Point(global); // 3 use object global to new a Point
    *heap = local;
    Point pa[ 4 ] = { local, *heap }; // 4, 5
    //pa is array, when use local, *heap to initialize, it will call copy constructor to make two  //new objects
    return *heap; // 6
}