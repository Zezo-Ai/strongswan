ipseclib_LTLIBRARIES = libstrongswan.la

libstrongswan_la_SOURCES = \
library.c \
asn1/asn1.c asn1/asn1_parser.c asn1/oid.c bio/bio_reader.c bio/bio_writer.c \
collections/blocking_queue.c collections/enumerator.c collections/hashtable.c \
collections/hashlist.c collections/array.c \
collections/linked_list.c crypto/crypters/crypter.c \
crypto/drbgs/drbg.c crypto/hashers/hasher.c \
crypto/hashers/hash_algorithm_set.c crypto/proposal/proposal.c \
crypto/proposal/proposal_keywords.c crypto/proposal/proposal_keywords_static.c \
crypto/prfs/prf.c crypto/prfs/mac_prf.c crypto/pkcs5.c \
crypto/rngs/rng.c crypto/rngs/rng_tester.c \
crypto/signers/signer.c \
crypto/signers/mac_signer.c crypto/crypto_factory.c crypto/crypto_tester.c \
crypto/key_exchange.c crypto/aead.c crypto/transform.c \
crypto/iv/iv_gen.c crypto/iv/iv_gen_rand.c crypto/iv/iv_gen_seq.c \
crypto/iv/iv_gen_null.c crypto/kdfs/kdf.c \
crypto/xofs/xof.c crypto/xofs/xof_bitspender.c \
credentials/credential_factory.c credentials/builder.c \
credentials/cred_encoding.c credentials/keys/private_key.c \
credentials/keys/public_key.c credentials/keys/shared_key.c \
credentials/keys/signature_params.c \
credentials/certificates/certificate.c credentials/certificates/crl.c \
credentials/certificates/ocsp_response.c credentials/certificates/x509.c \
credentials/certificates/ocsp_single_response.c \
credentials/certificates/certificate_printer.c \
credentials/containers/container.c credentials/containers/pkcs12.c \
credentials/credential_manager.c credentials/ocsp_responders.c \
credentials/sets/auth_cfg_wrapper.c credentials/sets/ocsp_response_wrapper.c \
credentials/sets/cert_cache.c credentials/sets/mem_cred.c \
credentials/sets/callback_cred.c credentials/auth_cfg.c database/database.c \
database/database_factory.c fetcher/fetcher.c fetcher/fetcher_manager.c eap/eap.c \
ipsec/ipsec_types.c \
metadata/metadata_factory.c metadata/metadata_int.c metadata/metadata_set.c \
networking/host.c networking/host_resolver.c networking/packet.c \
networking/tun_device.c networking/streams/stream_manager.c \
networking/streams/stream.c networking/streams/stream_service.c \
networking/streams/stream_tcp.c networking/streams/stream_service_tcp.c \
pen/pen.c plugins/plugin_loader.c plugins/plugin_feature.c processing/jobs/job.c \
processing/jobs/callback_job.c processing/processor.c processing/scheduler.c \
processing/watcher.c resolver/resolver_manager.c resolver/rr_set.c \
selectors/sec_label.c selectors/traffic_selector.c selectors/traffic_selector_list.c \
settings/settings.c settings/settings_types.c \
settings/settings_parser.y settings/settings_lexer.l utils/cpu_feature.c \
utils/utils.c utils/chunk.c utils/debug.c utils/enum.c utils/identification.c \
utils/lexparser.c utils/optionsfrom.c utils/capabilities.c utils/backtrace.c \
utils/parser_helper.c utils/test.c utils/process.c utils/utils/strerror.c \
utils/utils/atomics.c utils/utils/string.c utils/utils/memory.c \
utils/utils/tty.c utils/utils/path.c utils/utils/status.c utils/utils/time.c \
utils/utils/align.c

if !USE_WINDOWS
  libstrongswan_la_SOURCES += \
    threading/thread.c \
    threading/thread_value.c \
    threading/mutex.c \
    threading/rwlock.c \
    threading/spinlock.c \
    threading/semaphore.c \
    networking/streams/stream_unix.c \
    networking/streams/stream_service_unix.c
endif

if USE_VM_SOCKETS
  libstrongswan_la_SOURCES += \
    networking/streams/stream_vsock.c \
    networking/streams/stream_service_vsock.c
endif

# private header files
noinst_HEADERS = \
settings/settings_types.h

if USE_DEV_HEADERS
strongswan_includedir = ${dev_headers}
nobase_strongswan_include_HEADERS = \
library.h \
asn1/asn1.h asn1/asn1_parser.h asn1/oid.h bio/bio_reader.h bio/bio_writer.h \
collections/blocking_queue.h collections/enumerator.h collections/hashtable.h \
collections/hashtable_profiler.h \
collections/linked_list.h collections/array.h collections/dictionary.h \
crypto/crypters/crypter.h crypto/drbgs/drbg.h crypto/hashers/hasher.h \
crypto/hashers/hash_algorithm_set.h crypto/mac.h crypto/proposal/proposal.h \
crypto/proposal/proposal_keywords.h crypto/proposal/proposal_keywords_static.h \
crypto/rngs/rng.h crypto/rngs/rng_tester.h \
crypto/prfs/prf.h crypto/prfs/mac_prf.h crypto/nonce_gen.h \
crypto/signers/signer.h crypto/signers/mac_signer.h \
crypto/crypto_factory.h crypto/crypto_tester.h crypto/key_exchange.h \
crypto/aead.h crypto/transform.h crypto/pkcs5.h crypto/iv/iv_gen.h \
crypto/iv/iv_gen_rand.h crypto/iv/iv_gen_seq.h crypto/iv/iv_gen_null.h \
crypto/xofs/xof.h crypto/xofs/xof_bitspender.h crypto/xofs/mgf1.h \
crypto/kdfs/kdf.h \
credentials/credential_factory.h credentials/builder.h \
credentials/cred_encoding.h credentials/keys/private_key.h \
credentials/keys/public_key.h credentials/keys/shared_key.h \
credentials/keys/signature_params.h \
credentials/certificates/certificate.h credentials/certificates/x509.h \
credentials/certificates/ac.h credentials/certificates/crl.h \
credentials/certificates/pkcs10.h credentials/certificates/ocsp_request.h \
credentials/certificates/ocsp_single_response.h \
credentials/certificates/ocsp_response.h \
credentials/certificates/pgp_certificate.h \
credentials/certificates/certificate_printer.h \
credentials/containers/container.h credentials/containers/pkcs7.h \
credentials/containers/pkcs12.h \
credentials/credential_manager.h credentials/ocsp_responders.h \
credentials/ocsp_responder.h \
credentials/sets/auth_cfg_wrapper.h credentials/sets/ocsp_response_wrapper.h \
credentials/sets/cert_cache.h credentials/sets/mem_cred.h \
credentials/sets/callback_cred.h credentials/auth_cfg.h \
credentials/credential_set.h credentials/cert_validator.h \
database/database.h database/database_factory.h fetcher/fetcher.h \
fetcher/fetcher_manager.h eap/eap.h pen/pen.h ipsec/ipsec_types.h \
metadata/metadata.h metadata/metadata_factory.h metadata/metadata_int.h \
metadata/metadata_set.h \
networking/host.h networking/host_resolver.h networking/packet.h \
networking/tun_device.h networking/streams/stream.h \
networking/streams/stream_unix.h networking/streams/stream_service_unix.h \
networking/streams/stream_service_systemd.h \
networking/streams/stream_tcp.h networking/streams/stream_service_tcp.h \
networking/streams/stream_service.h networking/streams/stream_manager.h \
resolver/resolver.h resolver/resolver_response.h resolver/rr_set.h \
resolver/rr.h resolver/resolver_manager.h \
plugins/plugin_loader.h plugins/plugin.h plugins/plugin_feature.h \
processing/jobs/job.h processing/jobs/callback_job.h processing/processor.h \
processing/scheduler.h processing/watcher.h \
selectors/sec_label.h selectors/traffic_selector.h selectors/traffic_selector_list.h \
settings/settings.h settings/settings_parser.h threading/thread_value.h \
threading/thread.h threading/windows/thread.h \
threading/mutex.h threading/condvar.h threading/spinlock.h threading/semaphore.h \
threading/rwlock.h threading/rwlock_condvar.h threading/lock_profiler.h \
utils/utils.h utils/chunk.h utils/debug.h utils/enum.h utils/identification.h \
utils/lexparser.h utils/optionsfrom.h utils/capabilities.h utils/backtrace.h \
utils/cpu_feature.h utils/leak_detective.h utils/printf_hook/printf_hook.h \
utils/printf_hook/printf_hook_vstr.h utils/printf_hook/printf_hook_builtin.h \
utils/parser_helper.h utils/test.h utils/integrity_checker.h utils/process.h \
utils/utils/strerror.h utils/compat/windows.h utils/compat/apple.h utils/compat/android.h \
utils/utils/atomics.h utils/utils/types.h utils/utils/byteorder.h \
utils/utils/string.h utils/utils/memory.h utils/utils/tty.h utils/utils/path.h \
utils/utils/status.h utils/utils/object.h utils/utils/time.h utils/utils/align.h
if USE_VM_SOCKETS
  nobase_strongswan_include_HEADERS += \
    networking/streams/stream_vsock.h \
    networking/streams/stream_service_vsock.h
endif
endif

library.lo :	$(top_builddir)/config.status

libstrongswan_la_LIBADD = \
	$(DLLIB) $(ATOMICLIB)  $(BTLIB) $(SOCKLIB) \
	$(RTLIB) $(BFDLIB) $(UNWINDLIB) \
	$(selinux_LIBS)

AM_CPPFLAGS = \
	-I$(top_srcdir)/src/libstrongswan \
	-DIPSEC_DIR=\"${ipsecdir}\" \
	-DIPSEC_LIB_DIR=\"${ipseclibdir}\" \
	-DPLUGINDIR=\"${plugindir}\" \
	-DSTRONGSWAN_CONF=\"${strongswan_conf}\"

AM_CFLAGS = \
	$(selinux_CFLAGS) \
	@COVERAGE_CFLAGS@

AM_LDFLAGS = \
	-no-undefined

AM_YFLAGS = -v -d

if USE_WINDOWS
  libstrongswan_la_LIBADD += -lws2_32 -lpsapi
  libstrongswan_la_SOURCES += \
    threading/windows/thread.c \
    threading/windows/thread_value.c \
    threading/windows/mutex.c \
    threading/windows/rwlock.c \
    threading/windows/spinlock.c \
    threading/windows/semaphore.c \
    utils/compat/windows.c
else
  libstrongswan_la_LIBADD += $(PTHREADLIB)
endif

if USE_DBGHELP
  libstrongswan_la_LIBADD += -ldbghelp
  AM_CPPFLAGS += -DHAVE_DBGHELP
endif

if USE_LEAK_DETECTIVE
  AM_CPPFLAGS += -DLEAK_DETECTIVE
  libstrongswan_la_SOURCES += utils/leak_detective.c
endif

if USE_LOCK_PROFILER
  AM_CPPFLAGS += -DLOCK_PROFILER
endif

if USE_INTEGRITY_TEST
  AM_CPPFLAGS += -DINTEGRITY_TEST
  libstrongswan_la_SOURCES += utils/integrity_checker.c
endif

if USE_VSTR
  libstrongswan_la_SOURCES += utils/printf_hook/printf_hook_vstr.c
  libstrongswan_la_LIBADD += -lvstr
endif

if USE_BUILTIN_PRINTF
  libstrongswan_la_SOURCES += utils/printf_hook/printf_hook_builtin.c
  libstrongswan_la_LIBADD += -lm
endif

if !USE_BUILTIN_PRINTF
if !USE_VSTR
  libstrongswan_la_SOURCES += utils/printf_hook/printf_hook_glibc.c
endif
endif

if USE_LIBCAP
  libstrongswan_la_LIBADD += -lcap
endif

if USE_SYSTEMD
  AM_CPPFLAGS += $(systemd_CFLAGS) -DUSE_SYSTEMD
  libstrongswan_la_SOURCES += networking/streams/stream_service_systemd.c
  libstrongswan_la_LIBADD += $(systemd_LIBS)
endif

EXTRA_DIST = \
asn1/oid.txt asn1/oid.pl \
crypto/proposal/proposal_keywords_static.txt \
crypto/proposal/proposal_keywords_static.h.in \
plugins/plugin_constructors.py \
Android.mk

BUILT_SOURCES = \
$(srcdir)/asn1/oid.c $(srcdir)/asn1/oid.h \
$(srcdir)/crypto/proposal/proposal_keywords_static.h \
$(srcdir)/crypto/proposal/proposal_keywords_static.c \
settings/settings_parser.h

MAINTAINERCLEANFILES = \
$(srcdir)/asn1/oid.c $(srcdir)/asn1/oid.h \
$(srcdir)/crypto/proposal/proposal_keywords_static.h \
$(srcdir)/crypto/proposal/proposal_keywords_static.c

$(srcdir)/asn1/oid.c :	$(srcdir)/asn1/oid.pl $(srcdir)/asn1/oid.txt
		$(AM_V_GEN) \
		(cd $(srcdir)/asn1/ && $(PERL) oid.pl)

$(srcdir)/asn1/oid.h :	$(srcdir)/asn1/oid.pl $(srcdir)/asn1/oid.txt
		$(AM_V_GEN) \
		(cd $(srcdir)/asn1/ && $(PERL) oid.pl)

$(srcdir)/crypto/proposal/proposal_keywords_static.h: $(srcdir)/crypto/proposal/proposal_keywords_static.h.in
		$(AM_V_GEN) \
		sed \
		-e "s:\@GPERF_LEN_TYPE\@:$(GPERF_LEN_TYPE):" \
		$(srcdir)/crypto/proposal/proposal_keywords_static.h.in > $@

$(srcdir)/crypto/proposal/proposal_keywords_static.c:	$(srcdir)/crypto/proposal/proposal_keywords_static.txt \
														$(srcdir)/crypto/proposal/proposal_keywords_static.h
		$(AM_V_GEN) \
		$(GPERF) -N proposal_get_token_static -m 10 -C -G -c -t -D \
			--output-file=$@ $(srcdir)/crypto/proposal/proposal_keywords_static.txt

if STATIC_PLUGIN_CONSTRUCTORS
BUILT_SOURCES += $(srcdir)/plugin_constructors.c
CLEANFILES = $(srcdir)/plugin_constructors.c

$(srcdir)/plugin_constructors.c: $(srcdir)/plugins/plugin_constructors.py
		$(AM_V_GEN) \
		$(PYTHON) $(srcdir)/plugins/plugin_constructors.py ${s_plugins} > $@
endif

if MONOLITHIC
SUBDIRS =
else
SUBDIRS = .
endif

# build plugins with their own Makefile
#######################################

if USE_AF_ALG
  SUBDIRS += plugins/af_alg
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/af_alg/libstrongswan-af-alg.la
endif
endif

if USE_AES
  SUBDIRS += plugins/aes
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/aes/libstrongswan-aes.la
endif
endif

if USE_DES
  SUBDIRS += plugins/des
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/des/libstrongswan-des.la
endif
endif

if USE_BLOWFISH
  SUBDIRS += plugins/blowfish
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/blowfish/libstrongswan-blowfish.la
endif
endif

if USE_RC2
  SUBDIRS += plugins/rc2
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/rc2/libstrongswan-rc2.la
endif
endif

if USE_MD4
  SUBDIRS += plugins/md4
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/md4/libstrongswan-md4.la
endif
endif

if USE_MD5
  SUBDIRS += plugins/md5
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/md5/libstrongswan-md5.la
endif
endif

if USE_SHA1
  SUBDIRS += plugins/sha1
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/sha1/libstrongswan-sha1.la
endif
endif

if USE_SHA2
  SUBDIRS += plugins/sha2
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/sha2/libstrongswan-sha2.la
endif
endif

if USE_SHA3
  SUBDIRS += plugins/sha3
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/sha3/libstrongswan-sha3.la
endif
endif

if USE_GMP
  SUBDIRS += plugins/gmp
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/gmp/libstrongswan-gmp.la
endif
endif

if USE_CURVE25519
  SUBDIRS += plugins/curve25519
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/curve25519/libstrongswan-curve25519.la
endif
endif

if USE_RDRAND
  SUBDIRS += plugins/rdrand
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/rdrand/libstrongswan-rdrand.la
endif
endif

if USE_AESNI
  SUBDIRS += plugins/aesni
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/aesni/libstrongswan-aesni.la
endif
endif

if USE_RANDOM
  SUBDIRS += plugins/random
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/random/libstrongswan-random.la
endif
endif

if USE_NONCE
  SUBDIRS += plugins/nonce
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/nonce/libstrongswan-nonce.la
endif
endif

if USE_HMAC
  SUBDIRS += plugins/hmac
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/hmac/libstrongswan-hmac.la
endif
endif

if USE_KDF
  SUBDIRS += plugins/kdf
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/kdf/libstrongswan-kdf.la
endif
endif

if USE_CMAC
  SUBDIRS += plugins/cmac
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/cmac/libstrongswan-cmac.la
endif
endif

if USE_XCBC
  SUBDIRS += plugins/xcbc
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/xcbc/libstrongswan-xcbc.la
endif
endif

if USE_X509
  SUBDIRS += plugins/x509
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/x509/libstrongswan-x509.la
endif
endif

if USE_REVOCATION
  SUBDIRS += plugins/revocation
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/revocation/libstrongswan-revocation.la
endif
endif

if USE_CONSTRAINTS
  SUBDIRS += plugins/constraints
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/constraints/libstrongswan-constraints.la
endif
endif

if USE_ACERT
  SUBDIRS += plugins/acert
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/acert/libstrongswan-acert.la
endif
endif

if USE_PUBKEY
  SUBDIRS += plugins/pubkey
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/pubkey/libstrongswan-pubkey.la
endif
endif

if USE_PKCS1
  SUBDIRS += plugins/pkcs1
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/pkcs1/libstrongswan-pkcs1.la
endif
endif

if USE_PKCS7
  SUBDIRS += plugins/pkcs7
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/pkcs7/libstrongswan-pkcs7.la
endif
endif

if USE_PKCS8
  SUBDIRS += plugins/pkcs8
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/pkcs8/libstrongswan-pkcs8.la
endif
endif

if USE_PKCS12
  SUBDIRS += plugins/pkcs12
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/pkcs12/libstrongswan-pkcs12.la
endif
endif

if USE_OPENXPKI
  SUBDIRS += plugins/openxpki
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/openxpki/libstrongswan-openxpki.la
endif
endif

if USE_PGP
  SUBDIRS += plugins/pgp
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/pgp/libstrongswan-pgp.la
endif
endif

if USE_DNSKEY
  SUBDIRS += plugins/dnskey
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/dnskey/libstrongswan-dnskey.la
endif
endif

if USE_SSHKEY
  SUBDIRS += plugins/sshkey
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/sshkey/libstrongswan-sshkey.la
endif
endif

if USE_PEM
  SUBDIRS += plugins/pem
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/pem/libstrongswan-pem.la
endif
endif

if USE_CURL
  SUBDIRS += plugins/curl
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/curl/libstrongswan-curl.la
endif
endif

if USE_FILES
  SUBDIRS += plugins/files
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/files/libstrongswan-files.la
endif
endif

if USE_WINHTTP
  SUBDIRS += plugins/winhttp
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/winhttp/libstrongswan-winhttp.la
endif
endif

if USE_UNBOUND
  SUBDIRS += plugins/unbound
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/unbound/libstrongswan-unbound.la
endif
endif

if USE_SOUP
  SUBDIRS += plugins/soup
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/soup/libstrongswan-soup.la
endif
endif

if USE_LDAP
  SUBDIRS += plugins/ldap
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/ldap/libstrongswan-ldap.la
endif
endif

if USE_MYSQL
  SUBDIRS += plugins/mysql
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/mysql/libstrongswan-mysql.la
endif
endif

if USE_SQLITE
  SUBDIRS += plugins/sqlite
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/sqlite/libstrongswan-sqlite.la
endif
endif

if USE_PADLOCK
  SUBDIRS += plugins/padlock
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/padlock/libstrongswan-padlock.la
endif
endif

if USE_OPENSSL
  SUBDIRS += plugins/openssl
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/openssl/libstrongswan-openssl.la
endif
endif

if USE_WOLFSSL
  SUBDIRS += plugins/wolfssl
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/wolfssl/libstrongswan-wolfssl.la
endif
endif

if USE_GCRYPT
  SUBDIRS += plugins/gcrypt
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/gcrypt/libstrongswan-gcrypt.la
endif
endif

if USE_BOTAN
  SUBDIRS += plugins/botan
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/botan/libstrongswan-botan.la
endif
endif

if USE_FIPS_PRF
  SUBDIRS += plugins/fips_prf
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/fips_prf/libstrongswan-fips-prf.la
endif
endif

if USE_AGENT
  SUBDIRS += plugins/agent
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/agent/libstrongswan-agent.la
endif
endif

if USE_KEYCHAIN
  SUBDIRS += plugins/keychain
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/keychain/libstrongswan-keychain.la
endif
endif

if USE_PKCS11
  SUBDIRS += plugins/pkcs11
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/pkcs11/libstrongswan-pkcs11.la
endif
endif

if USE_CHAPOLY
  SUBDIRS += plugins/chapoly
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/chapoly/libstrongswan-chapoly.la
endif
endif

if USE_CTR
  SUBDIRS += plugins/ctr
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/ctr/libstrongswan-ctr.la
endif
endif

if USE_CCM
  SUBDIRS += plugins/ccm
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/ccm/libstrongswan-ccm.la
endif
endif

if USE_GCM
  SUBDIRS += plugins/gcm
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/gcm/libstrongswan-gcm.la
endif
endif

if USE_MGF1
  SUBDIRS += plugins/mgf1
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/mgf1/libstrongswan-mgf1.la
endif
endif

if USE_DRBG
  SUBDIRS += plugins/drbg
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/drbg/libstrongswan-drbg.la
endif
endif

if USE_ML
  SUBDIRS += plugins/ml
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/ml/libstrongswan-ml.la
endif
endif

if USE_TEST_VECTORS
  SUBDIRS += plugins/test_vectors
if MONOLITHIC
  libstrongswan_la_LIBADD += plugins/test_vectors/libstrongswan-test-vectors.la
endif
endif

if MONOLITHIC
  SUBDIRS += .
endif

# build unit tests
##################

SUBDIRS += tests

