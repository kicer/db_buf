#ifndef _DB_BUF_H_
#define _DB_BUF_H_


/* Dobule-Buffer
 * last/current/lock
 */
#define DB_BUF_INIT(type, name)                             \
	unsigned _db_curt_##name = 0;                       \
	unsigned _db_last_##name = 1;                       \
	type _db_var_##name[2]

#define DB_BUF_SET(name, value)                             \
	do {                                                \
		unsigned v = _db_curt_##name;               \
		_db_var_##name[v] = (value);                \
		_db_last_##name = _db_curt_##name;          \
		_db_curt_##name = v;                        \
	} while(0)

#define DB_BUF_GET(name) (_db_var_##name[_db_last_##name])


#endif /* _DB_BUF_H_ */
