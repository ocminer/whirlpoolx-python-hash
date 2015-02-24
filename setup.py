from distutils.core import setup, Extension

whirlpoolx_hash_module = Extension('whirlpoolx_hash',
                               sources = ['whirlpoolxmodule.c',
                                          'whirlpoolx.c',
										  'sha3/sph_whirlpool.c'],
                               include_dirs=['.', './sha3'])

setup (name = 'whirlpoolx_hashs',
       version = '1.0',
       description = 'Bindings for proof of work used by Vanillacoin',
       ext_modules = [whirlpoolx_hash_module])
