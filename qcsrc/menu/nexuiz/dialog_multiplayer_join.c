#ifdef INTERFACE
CLASS(NexuizServerListTab) EXTENDS(NexuizTab)
	METHOD(NexuizServerListTab, fill, void(entity))
	ATTRIB(NexuizServerListTab, title, string, _("Join"))
	ATTRIB(NexuizServerListTab, intendedWidth, float, 0.9)
	ATTRIB(NexuizServerListTab, rows, float, 22)
	ATTRIB(NexuizServerListTab, columns, float, 6.5)
ENDCLASS(NexuizServerListTab)
entity makeNexuizServerListTab();
#endif

#ifdef IMPLEMENTATION

entity makeNexuizServerListTab()
{
	entity me;
	me = spawnNexuizServerListTab();
	me.configureDialog(me);
	return me;
}
void fillNexuizServerListTab(entity me)
{
	entity e, slist, btn;

	slist  = makeNexuizServerList();

	me.TR(me);
		me.TD(me, 1, 0.5, e = makeNexuizTextLabel(0, _("Filter:")));
		me.TD(me, 1, 0.5, btn = makeNexuizButton(_("Clear"), '0 0 0'));
			btn.onClick = InputBox_Clear_Click;
		me.TD(me, 1, me.columns - 2.5, e = makeNexuizInputBox(0, NULL));
			e.onChange = ServerList_Filter_Change;
			e.onChangeEntity = slist;
			btn.onClickEntity = e;
			slist.controlledTextbox = e;
		me.TD(me, 1, 0.5, e = makeNexuizCheckBox(0, "menu_slist_showempty", _("Empty")));
			slist.filterShowEmpty = e.checked;
			e.onClickEntity = slist;
			e.onClick = ServerList_ShowEmpty_Click;
		me.TD(me, 1, 0.5, e = makeNexuizCheckBox(0, "menu_slist_showfull", _("Full")));
			slist.filterShowFull = e.checked;
			e.onClickEntity = slist;
			e.onClick = ServerList_ShowFull_Click;
		me.TD(me, 1, 0.5, e = makeNexuizCheckBox(0, "net_slist_pause", _("Pause")));

	me.TR(me);
		me.TD(me, 1, 1, slist.sortButton1 = makeNexuizButton(NULL, '0 0 0'));
		me.TD(me, 1, 1, slist.sortButton2 = makeNexuizButton(NULL, '0 0 0'));
		me.TD(me, 1, 1, slist.sortButton3 = makeNexuizButton(NULL, '0 0 0'));
		me.TD(me, 1, 1, slist.sortButton4 = makeNexuizButton(NULL, '0 0 0'));
		me.TD(me, 1, 1, slist.sortButton5 = makeNexuizButton(NULL, '0 0 0'));
	me.TR(me);
		me.TD(me, me.rows - 4, me.columns, slist);

	me.gotoRC(me, me.rows - 2, 0);
		me.TD(me, 1, 0.6, e = makeNexuizTextLabel(0, _("Address:")));
		me.TD(me, 1, 2.9, e = makeNexuizInputBox(0, NULL));
			e.onEnter = ServerList_Connect_Click;
			e.onEnterEntity = slist;
			slist.ipAddressBox = e;
		me.TD(me, 1, 1.5, e = makeNexuizButton("", '0 0 0'));
			e.onClick = ServerList_Favorite_Click;
			e.onClickEntity = slist;
			slist.favoriteButton = e;
		me.TD(me, 1, 1.5, e = makeNexuizButton(_("Info"), '0 0 0'));
			e.onClick = ServerList_Info_Click;
			e.onClickEntity = slist;
			slist.infoButton = e;
	me.TR(me);
		me.TD(me, 1, me.columns, e = makeNexuizButton(_("Join!"), '0 0 0'));
			e.onClick = ServerList_Connect_Click;
			e.onClickEntity = slist;
			slist.connectButton = e;
}
#endif
