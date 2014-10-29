Name:           ros-indigo-smclib
Version:        1.7.15
Release:        0%{?dist}
Summary:        ROS smclib package

Group:          Development/Libraries
License:        Mozilla Public License Version 1.1
URL:            http://smc.sourceforge.net/
Source0:        %{name}-%{version}.tar.gz

BuildArch:      noarch

BuildRequires:  ros-indigo-catkin

%description
The State Machine Compiler (SMC) from http://smc.sourceforge.net/ converts a
language-independent description of a state machine into the source code to
support that state machine. This package contains the libraries that a compiled
state machine depends on, but it does not contain the compiler itself.

%prep
%setup -q

%build
# In case we're installing to a non-standard location, look for a setup.sh
# in the install tree that was dropped by catkin, and source it.  It will
# set things like CMAKE_PREFIX_PATH, PKG_CONFIG_PATH, and PYTHONPATH.
if [ -f "/opt/ros/indigo/setup.sh" ]; then . "/opt/ros/indigo/setup.sh"; fi
mkdir -p build && cd build
%cmake .. \
        -UINCLUDE_INSTALL_DIR \
        -ULIB_INSTALL_DIR \
        -USYSCONF_INSTALL_DIR \
        -USHARE_INSTALL_PREFIX \
        -ULIB_SUFFIX \
        -DCMAKE_INSTALL_PREFIX="/opt/ros/indigo" \
        -DCMAKE_PREFIX_PATH="/opt/ros/indigo" \
        -DSETUPTOOLS_DEB_LAYOUT=OFF \
        -DCATKIN_BUILD_BINARY_PACKAGE="1" \

make %{?_smp_mflags}

%install
# In case we're installing to a non-standard location, look for a setup.sh
# in the install tree that was dropped by catkin, and source it.  It will
# set things like CMAKE_PREFIX_PATH, PKG_CONFIG_PATH, and PYTHONPATH.
if [ -f "/opt/ros/indigo/setup.sh" ]; then . "/opt/ros/indigo/setup.sh"; fi
cd build
make %{?_smp_mflags} install DESTDIR=%{buildroot}

%files
/opt/ros/indigo

%changelog
* Tue Oct 28 2014 Esteve Fernandez <esteve@osrfoundation.org> - 1.7.15-0
- Autogenerated by Bloom

