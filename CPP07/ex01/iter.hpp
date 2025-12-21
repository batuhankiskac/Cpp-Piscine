#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename F>
void iter(T *arr, const int len, F function) {
	for (int i = 0; i < len; ++i)
		function(arr[i]);
}

#endif
