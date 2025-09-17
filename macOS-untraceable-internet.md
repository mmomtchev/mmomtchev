# Creating a completely untraceable Internet connection on macOS

**A guide for network and OS-savvy people on the run from a first-world state-sponsored extortion scheme.**

This tutorial will show you how to create a completely untraceable Internet connection using macOS and publicly-available Wi-Fi networks. As a law-abiding citizen fighting criminal corruption, I won't cover `aircrack-ng`. There are plenty of publicly-available Wi-Fi networks in most major metropolitan areas and you can stay on the good side of the law without compromising your own safety.

First of all, should you be tempted to simply connect to public Wi-Fi APs and then to use Tor to access the Internet, you should know that any modern computer will immediately betray you. It will make tons of connections to services such as iCloud (on macOS), Google (if you use Chrome), Spotify (if you use it), VSCode configuration syncing, Whatsapp, autoupdaters, whatever... All those services cannot be easily made to use Tor and will give up your IP address the very moment you connect.

The goal of this setup is to preserve perfectly the secrecy of the entry Wi-Fi AP in such extreme cases as mine where my telecom operator and Big Tech - including Google, Microsoft and Twitter - are actively collaborating with the extortion scheme.

The setup uses a Linux guest running Tor exposed to the host macOS via a SOCKS5 proxy through which OpenVPN connects. This allows for a perfectly normal - albeit somewhat slower - Internet experience where everything works. Remote servers see a connection coming from the public OpenVPN server. People tracing the OpenVPN server see only a connection coming from a Tor exit node. People managing the Wi-Fi AP see simply a plain Linux computer connecting to the Internet and using Tor - if you go for the fast mode - or simply browsing the Internet - if you go for the slower bridged mode.

## Prerequisites

- a macOS computer
- an external USB Wi-Fi adapter - high powered antennas work best but are not mandatory
- a publicly hosted server that will serve as the public origin of your connection if you need one (some services such as `ssh` require it)
- VMWare Fusion with a Linux guest

## The Linux router

Install the Linux router guest using host-only networking and pass the external USB Wi-Fi adapter directly to the guest. I won't cover the installation of the Linux guest, you certainly can do this yourself. Make sure you see both the host-only network adapter which will appear as an Ethernet device and the external USB Wi-Fi adapter. Do not use any personally identifiable information in this guest. Connect to the AP normally. You can install a GUI - or you can do as me and use XQuarts on the macOS host and launch a browser remotely on a text-only headless Linux guest. You will need the browser because most public APs have captive portals that require JavaScript. Make sure the host-only connection works. Check the IP address on the Linux guest and use `ssh` from the macOS host.

## Tor

## OpenVPN

## Creating a new macOS *Network Service*

VMware Fusion creates a bridge for the host-only network, but it is not identified in the macOS GUI as a valid network adapter.

We will have to create a new network adapter to make the macOS GUI work with it.

Identify the VMWare Fusion device by using `ifconfig` (look at the IP address) - it will usually be `bridge100` (or maybe `bridge101` if you have another virtual machine).

Start by creating a macOS *hardware port* tied to `bridge100`:

```shell
sudo plutil -insert VirtualNetworkInterfaces.Bridge.bridge100 -dictionary -append /Library/Preferences/SystemConfiguration/preferences.plist
sudo plutil -insert VirtualNetworkInterfaces.Bridge.bridge100.Interfaces -array /Library/Preferences/SystemConfiguration/preferences.plist
sudo plutil -insert VirtualNetworkInterfaces.Bridge.bridge100.UserDefinedName -string "VMWareFusion100" /Library/Preferences/SystemConfiguration/preferences.plist
```

Now you should have a new *hardware port* in `networksetup`:

```shell
sudo networksetup -listallhardwareports
```

Then, create a new macOS *network service* tied to this *hardware port* with the existing IP addresses. The first IP address is the IP address of the macOS host on this virtual network and the second one is the IP address of the Linux guest which will be the router.

Do not worry, you won't leak anything at this point - the Linux router is not set up for masquerading.

```shell
sudo networksetup -createnetworkservice Tor VMWareFusion100
sudo networksetup -setmanual Tor 192.168.108.1 255.255.255.0 192.168.108.128
```

Now if you go to `System Settings... / Network` you will notice a new network adapter called `Tor` along any eventual Wi-Fi and Ethernet adapters. This will be your untraceable connection.

After your network adapter is created, you should delete the *hardware port* - this device is managed by VMWare Fusion and you do not want the macOS system to create it at the next reboot. You do not need it - the *network service* references `bridge100` directly.

```shell
sudo plutil -remove VirtualNetworkInterfaces.Bridge.bridge100 /Library/Preferences/SystemConfiguration/preferences.plist
```

# Playing mobile games on your phone while preserving the secrecy of the AP

At this point it will be possible to use the internal macOS Wi-Fi adapter in connection sharing mode to connect your mobile phone - provided that you remove the SIM card.
