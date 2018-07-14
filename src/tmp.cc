 /// @date    2018-07-09 20:26:43
 
#include "Index.h"
#include "DictProducer.h"

int main() {
#if 0
	Index index("dict_The_Holy_Bible.txt");
	index.read_dict();
	index.show_readIn();
	index.store_index();
#endif
	DictProducer dict;
	dict.build_dict();
	dict.show_dict();
}
