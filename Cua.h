#ifndef _CUA_H_
	#define _CUA_H_

	typedef struct N{
		Element e;
		struct N *seg;
	} Node;

	typedef struct{
		Node *cap;
		Node *ult;
	} Cua;

	Cua CUA_crea();
	void CUA_encua(Cua *c, Element e);
	void CUA_desencua(Cua *c);
	Element CUA_cap(Cua c);
	int CUA_buida(Cua c);
	void CUA_destrueix(Cua *c);

	#endif