SUBDIRS = runtime
DIST_SUBDIRS = runtime samples
datadir=$(prefix)

data_DATA = INSTALL README LICENSE COPYING NOTICE GettingStarted.html
EXTRA_DIST = LICENSE COPYING INSTALL README NOTICE sdotest.sh GettingStarted.html doc
dist-hook:
	rm -rf `find $(distdir)/ -type d -name .svn`
	rm -rf `find $(distdir)/ -type d -name .deps`

install-data-hook:
	rm -rf $(prefix)/samples
	cp -r samples $(prefix)
	rm -rf `find $(prefix)/samples -type d -name .svn`
	rm -rf `find $(prefix)/samples -type d -name .deps`
	rm -rf $(prefix)/doc
	cp -r doc $(prefix)
	rm -rf `find $(prefix)/doc -type d -name .svn`
	rm -rf `find $(prefix)/doc -type d -name .deps`
	
bindist: dist
	rm -rf ${PACKAGE}-${PACKAGE_VERSION}
	rm -rf ${PACKAGE}-${PACKAGE_VERSION}-src
	rm -rf ${PACKAGE}-${PACKAGE_VERSION}-bin
	gunzip -f ${PACKAGE}-${PACKAGE_VERSION}.tar.gz
	tar -xf ${PACKAGE}-${PACKAGE_VERSION}.tar
	mv ${PACKAGE}-${PACKAGE_VERSION} ${PACKAGE}-${PACKAGE_VERSION}-src
	tar -cf - ${PACKAGE}-${PACKAGE_VERSION}-src | gzip -c > ${PACKAGE}-${PACKAGE_VERSION}-src.tar.gz
	cd ${PACKAGE}-${PACKAGE_VERSION}-src \
	&&	sh ../makebindist.sh
	mkdir ${PACKAGE}-${PACKAGE_VERSION}-bin
	cp -r ${PACKAGE}-${PACKAGE_VERSION}-src/deploy/* ${PACKAGE}-${PACKAGE_VERSION}-bin
	tar -cf - ${PACKAGE}-${PACKAGE_VERSION}-bin | gzip -c > ${PACKAGE}-${PACKAGE_VERSION}-bin.tar.gz
