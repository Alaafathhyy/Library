double BS_double() {
	double st = 0, en = 1e9;
	double size = en - st;
	for (size /= 2; size > 1e-7; size /= 2) {
		if (!valid(st + size))
			st += size;
	}
}
}
