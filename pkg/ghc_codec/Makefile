PKG_NAME    = ghc_codec
PKG_URL     = https://github.com/A-Paul/ghc_codec.git
PKG_VERSION = 631d33504b25258cd4a048f72f6dffec3af48939
PKG_LICENSE = LGPLv2.1

GHC_ENCODER_IMPL ?= naive
export GHC_ENCODER_IMPL

.PHONY: all
#.IGNORE: all

#???
#include $(RIOTBASE)/pkg/pkg.mk

all: git-download
#	Pathetic reverse engineering
	@echo :CURDIR:$(CURDIR):
	@echo :PKGDIRBASE:$(PKGDIRBASE):
	@echo :RIOTPKG:$(RIOTPKG):
	@echo :PKG_BUILDDIR:$(PKG_BUILDDIR):
	@echo :CURDIR:$(value CURDIR):
	@echo :PKGDIRBASE:$(value PKGDIRBASE):
	@echo :RIOTPKG:$(value RIOTPKG):
	@echo :PKG_BUILDDIR:$(vlaue PKG_BUILDDIR):
#	Real stuff begins
	$(RM) $(PKG_BUILDDIR)/src/Makefile
#	$(CP) $(CURDIR)/Makefile.$(PKG_NAME) $(PKG_BUILDDIR)/src/Makefile
	$(MAKE) -C $(PKG_BUILDDIR)/src -f $(CURDIR)/Makefile.$(PKG_NAME)

include $(RIOTBASE)/pkg/pkg.mk
