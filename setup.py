from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext
import sys
import setuptools

class get_pybind_include(object):
    def __init__(self, user=False):
        self.user = user

    def __str__(self):
        import pybind11
        return pybind11.get_include(self.user)

# Compiler flags
extra_compile_args = ['-std=c++11']
if sys.platform == 'darwin':
    extra_compile_args += ['-stdlib=libc++']

ext_modules = [
    Extension(
        "dsmga2.dsmga2",
        ["src/python_binding/ga_wrapper.cpp",
         "src/core/chromosome.cpp",
         "src/core/dsmga2.cpp",
         "src/core/fastcounting.cpp",
         "src/core/global.cpp",
         "src/utils/mt19937ar.cpp",
         "src/utils/myrand.cpp",
         "src/functions/spin.cpp",
         "src/functions/nk-wa.cpp",
         "src/functions/sat.cpp",
         "src/functions/fitness_functions.cpp"
         ],
        include_dirs=[
            get_pybind_include(),
            get_pybind_include(user=True),
            "src",
            "src/core",
            "src/functions",
            "src/utils"
        ],
        extra_compile_args=extra_compile_args,
        language='c++'
    ),
]

setup(
    name="dsmga2",
    version="0.0.1",
    author="Your Name",
    description="DSMGA-II optimization algorithm",
    ext_modules=ext_modules,
    packages=['dsmga2'],
    package_dir={'': 'python'},
    install_requires=['pybind11>=2.4.3'],
    setup_requires=['pybind11>=2.4.3'],
    cmdclass={'build_ext': build_ext},
    zip_safe=False,
) 