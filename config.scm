;; This is an operating system configuration generated
;; by the graphical installer.
;;
;; Once installation is complete, you can learn and modify
;; this file to tweak the system configuration, and pass it
;; to the 'guix system reconfigure' command to effect your
;; changes.


;; Indicate which modules to import to access the variables
;; used in this configuration.
(use-modules (gnu))
(use-service-modules cups desktop networking ssh xorg)

(operating-system
  (locale "pt_BR.utf8")
  (timezone "America/Sao_Paulo")
  (keyboard-layout (keyboard-layout "br"))
  (host-name "maycon")

  ;; The list of user accounts ('root' is implicit).
  (users (cons* (user-account
                  (name "maycon")
                  (comment "Maycon")
                  (group "users")
                  (home-directory "/home/maycon")
                  (supplementary-groups '("wheel" "netdev" "audio" "video")))
                %base-user-accounts))

  ;; Packages installed system-wide.  Users can also install packages
  ;; under their own account: use 'guix search KEYWORD' to search
  ;; for packages and 'guix install PACKAGE' to install a package.
  (packages (append (list (specification->package "openbox")
                          (specification->package "i3-wm")
			  (specification->package "polybar")

                          ;;(specification->package "i3status")
                          (specification->package "dmenu")
                          (specification->package "st")
                          (specification->package "emacs")
                          (specification->package "emacs-exwm")
                          (specification->package
                           "emacs-desktop-environment")) %base-packages))

  ;; Below is the list of system services.  To search for available
  ;; services, run 'guix system search KEYWORD' in a terminal.
  (services
   (append (list (service cups-service-type)
                 (set-xorg-configuration
                  (xorg-configuration (keyboard-layout keyboard-layout))))

           ;; This is the default list of services we
           ;; are appending to.
           %desktop-services))
  (bootloader (bootloader-configuration
                (bootloader grub-bootloader)
                (targets (list "/dev/sda"))
                (keyboard-layout keyboard-layout)))
  (swap-devices (list (swap-space
                        (target (uuid
                                 "b624f4a4-2bdb-4b8e-acf9-554813e4ff71")))))

  ;; The list of file systems that get "mounted".  The unique
  ;; file system identifiers there ("UUIDs") can be obtained
  ;; by running 'blkid' in a terminal.
  (file-systems (cons* (file-system
                         (mount-point "/")
                         (device (uuid
                                  "e7d58223-07d5-4a84-b25a-b80ea78a3e26"
                                  'ext4))
                         (type "ext4")) %base-file-systems)))
