#define noteline_send NoteLine_SendEntity //compatibility with save files
float noteline_send(entity to, float sf) {
	net_write_byte(MSG_ENTITY, NET_CSQC_NOTELINE);
	other = to;
	self.touch();
	net_write_string(MSG_ENTITY, self.message);
	net_write_string(MSG_ENTITY, self.target);
	net_write_string(MSG_ENTITY, self.target2);
	net_write_string(MSG_ENTITY, self.target3);
	self.message = "";
	self.target = "";
	self.target2 = "";
	self.target3 = "";
	return TRUE;
}

entity(void() msggen) noteline_new {
	entity e = spawn();
	e.touch = msggen;
	net_link_entity(e, FALSE, 0, NoteLine_SendEntity);
	return e;
}
