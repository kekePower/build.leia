# This can be used in cron scripts or if you don't want to always
# answer the two questions about clearing ccache and deleting PREFIX

DISABLE_CCACHE_Q=true
DISABLE_DELETE_PREFIX=true

# It is now possible to use --with=clean,nn together.
# This combination became a neccisity for me and hopefully you'll find it
# useful too.

if [[ ! ${CLEAN_IS_SET} ]]; then
# We also default a clean install with addons
CLEAN_IS_SET=true
ADDON_IS_SET=true
fi
