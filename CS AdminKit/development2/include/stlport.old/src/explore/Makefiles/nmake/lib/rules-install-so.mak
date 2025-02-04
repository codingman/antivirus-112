# Time-stamp: <03/10/26 16:42:14 ptr>
# $Id: rules-install-so.mak,v 1.1.2.3 2004/09/21 20:10:01 dums Exp $

!ifndef INSTALL_TAGS
INSTALL_TAGS= install-release-shared install-dbg-shared install-stldbg-shared install-release-static install-dbg-static install-stldbg-static
!endif

install:	$(INSTALL_TAGS)

install-shared: install-release-shared install-dbg-shared install-stldbg-shared

install-release-shared: release-shared $(INSTALL_BIN_DIR) $(INSTALL_LIB_DIR)
	$(INSTALL_SO) $(SO_NAME_OUT) $(INSTALL_BIN_DIR)
	$(INSTALL_SO) $(LIB_NAME_OUT) $(INSTALL_LIB_DIR)
	$(INSTALL_SO) $(EXP_NAME_OUT) $(INSTALL_LIB_DIR)

install-dbg-shared: dbg-shared $(INSTALL_BIN_DIR_DBG) $(INSTALL_LIB_DIR_DBG)
	$(INSTALL_SO) $(SO_NAME_OUT_DBG) $(INSTALL_BIN_DIR_DBG)
	$(INSTALL_SO) $(LIB_NAME_OUT_DBG) $(INSTALL_LIB_DIR_DBG)
	$(INSTALL_SO) $(EXP_NAME_OUT_DBG) $(INSTALL_LIB_DIR_DBG)

install-stldbg-shared: stldbg-shared $(INSTALL_BIN_DIR_STLDBG) $(INSTALL_LIB_DIR_STLDBG)
	$(INSTALL_SO) $(SO_NAME_OUT_STLDBG) $(INSTALL_BIN_DIR_STLDBG)
	$(INSTALL_SO) $(LIB_NAME_OUT_STLDBG) $(INSTALL_LIB_DIR_STLDBG)
	$(INSTALL_SO) $(EXP_NAME_OUT_STLDBG) $(INSTALL_LIB_DIR_STLDBG)
