from libcpp.string cimport string
import objlist_pb2

cdef extern from "objlist.h":
    int parse(string)

object_list = objlist_pb2.ObjectList()
for idx in range(10):
    obj = object_list.object.add()
    obj.id = idx
    obj.name = "obj%s" % idx

info_str = object_list.SerializeToString()
obj_ct = parse(info_str)
print "Number of objects: %d" % obj_ct
