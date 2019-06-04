commit 175a720cf40878a5472ab21cf413f94c33a50251
Author: JunyouLiu <17210240159@fudan.edu.cn>
Date:   Fri May 24 13:23:42 2019 +0800

    add deployment details

commit 8a43eb3bec1bc773a0c0f93ea5e3790f839053b1
Author: JunyouLiu <17210240159@fudan.edu.cn>
Date:   Thu May 23 10:18:54 2019 +0800

    add deployments list

commit 5d6b465e809fe7f475aa4af38e547ff545c2b1cb
Author: JunyouLiu <17210240159@fudan.edu.cn>
Date:   Tue May 21 09:56:05 2019 +0800

    latest

commit 5a03a8837dd88663c2f9b1ac75bf235833c56d59
Author: JunyouLiu <17210241059@fudan.edu.cn>
Date:   Sun Apr 28 22:57:56 2019 +0800

    add bigdataClusters Panel

commit ac80f35bbfa060ca56259e5564f8966be8f78fc6
Author: JunyouLiu <17210241059@fudan.edu.cn>
Date:   Sun Apr 28 20:02:20 2019 +0800

    commit

commit f878f531113d60738178daf66aec7e033db6dd3c
Author: Wang Tao <openstack@foxmail.com>
Date:   Fri Jan 11 11:08:00 2019 +0800

    Support commit image into glance

commit cb3e119d0905f5830a723c66b904680c758c7c06
Author: Wang Tao <openstack@foxmail.com>
Date:   Tue Jan 8 10:10:34 2019 +0800

    Support local directory mapping for container

commit 424f27f7922e40fc16b96ab6f9cfd75e1404c523
Author: Wang Tao <openstack@foxmail.com>
Date:   Fri Jan 4 10:29:12 2019 +0800

    Support destination host option for creating container

commit 4c245a9e842d1e94f2498c5601735dd233841107
Author: Wang Tao <openstack@foxmail.com>
Date:   Mon Dec 10 11:11:25 2018 +0800

    Support show NUMA topology in container list

commit 2d3a10f63143ec7dcc921321c177c05ced0e4e60
Author: Wang Tao <openstack@foxmail.com>
Date:   Mon Dec 3 11:59:46 2018 +0800

    Support creating containers with privileged option

commit 2f2aa2b9f1246d34fc7b320925eda23d76a6f803
Author: Wang Tao <openstack@foxmail.com>
Date:   Thu Nov 22 17:36:12 2018 +0800

    Support creating containers with cpu_policy option

commit 9413e3daa0cfa2957ce4b797ac2a6810ec81136b
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Thu Nov 15 06:09:04 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: I184d8bc272a6191de54f28036b74fb4245c8f6db

commit dc2bd25c69d8b7779b7f470b1658a58cb7d6d582
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Tue Nov 6 07:08:58 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: I3738d78b79e6a083f292dd8004927a5fb5f2afc4

commit 87ed29d77a27720bfab08360902ec986faf28ae0
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Thu Nov 1 06:49:36 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: I544416747c290316e61e0feebf976b7fbe7654c8

commit bb1685ad84e50b137da52c099027f1b8c8254dbb
Merge: f5d4d69 c2ffde0
Author: Zuul <zuul@review.openstack.org>
Date:   Wed Oct 31 03:43:11 2018 +0000

    Merge "Add containers panel for admin"

commit c2ffde09031b82567fb50a0901f066df81264ada
Author: Shu Muto <shu.mutow@gmail.com>
Date:   Thu Oct 25 17:46:02 2018 +0900

    Add containers panel for admin
    
    Add containers panel into admin dashboard with actions that restricted for admin.
    In details view, admin should not see logs tab and console tab.
    
    Allowed actions for admin
    - update
    - rebuild
    - start / stop / restart
    - kill
    - delete with force
    
    Not allowed actions for admin
    - create
    - manage security group
    - pause / unpause
    - execute
    - delete
    - delete with stop
    
    Not allowed view for admin
    - logs tab on details view
    - console tab on details view
    
    To enable containers panel for admin, copy following[1] into horizon's
    enabled folder[2].
    [1] zun_ui/enabled/_2333_admin_container_containers_panel.py
    [2] openstack_dashboard/local/enabled/
    
    Change-Id: I1f96464b0103e099bd58bc2889087e1b55f4ed97
    Implement: blueprint add-admin-containers-panel

commit f5d4d69da038024265d14182858009af8b100b64
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Fri Oct 26 07:50:48 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: I6faac9b7fb8a25f192ac599c84ca409c7156ef86

commit 7b9b3f2d5ce94b4d19bc7323de342afa6a8bb930
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Thu Oct 25 07:06:47 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: Iac2f5fc13521a996d89ef6f5d631db7f0d1192a8

commit eac9c36117ee5ff60ad00ea66b68cf67000113c2
Merge: 3f8cb50 e426b24
Author: Zuul <zuul@review.openstack.org>
Date:   Thu Oct 25 01:43:27 2018 +0000

    Merge "Add "host" column into images table view for admin"

commit e426b241923407fdacabbc7bf0bd2bb00383c4a2
Author: Shu Muto <shu.mutow@gmail.com>
Date:   Fri Oct 19 09:59:04 2018 +0900

    Add "host" column into images table view for admin
    
    Change-Id: Ia76d5bc53dd2d71897afc9fe214ca3c2111f06a9
    Closes-Bug: #1798702

commit 3f8cb502b68e9a32624ca7c5057cc873eac56293
Author: Shu Muto <shu.mutow@gmail.com>
Date:   Mon Oct 22 14:44:44 2018 +0900

    Remove 'host' parameter from deleting image
    
    'host' parameter for deleting image has removed from client.
    Zun UI should remove this parameter.
    
    Now, due to only 'id' is necessary for deleting image,
    we can use 'delete-selected' type action and common deletion
    confirmation dialog. Using the common deletion action,
    we can also implement deletion action as batch action.
    
    Change-Id: I2adae5cb466e620177c3788ac340f6464711e21d
    Closes-Bug: #1799125

commit 0022f4a0baac2c0d50489ea7d1ad40a9524f0377
Author: Shu Muto <shu.mutow@gmail.com>
Date:   Wed Oct 24 16:33:12 2018 +0900

    Replace @memoized_with_request to @memoized
    
    Horizon replaced @memoized_with_request to @memoized
    for client module. Plugins need to replace it as same as
    Horizon.
    
    Change-Id: I050bc27236700b8469890468efba46bec5c7d246
    Closes-Bug: #1799650

commit 3cd7a2c33515814572ea3cb9652d8b9034fe4e2a
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Mon Oct 22 07:00:29 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: Ia4242003195164eed1e0c24c6a1542b83ed5b691

commit 97ecdabee452c430a82f3b72e52938d810be70ea
Merge: 4803754 ddb3106
Author: Zuul <zuul@review.openstack.org>
Date:   Fri Oct 19 03:45:30 2018 +0000

    Merge "Add details view for hosts panel"

commit 48037543ab2c78b4d199f1f786bff1c150614e05
Merge: 7ebff51 761a31b
Author: Zuul <zuul@review.openstack.org>
Date:   Thu Oct 18 08:01:20 2018 +0000

    Merge "Fix an issue of default api version"

commit ddb31065ab98fb4641416a6a812d318fa6e1f1f3
Author: Shu Muto <shu.mutow@gmail.com>
Date:   Tue Oct 16 18:52:22 2018 +0900

    Add details view for hosts panel
    
    This patch adds host details view for admin.
    
    Change-Id: I99a7429f226bf62edea2f745e844c963099a48e8
    Implements: blueprint add-host-panel

commit 761a31bc4be14a25804ee7bc9e25fa4557f084a9
Author: Hongbin Lu <hongbin034@gmail.com>
Date:   Wed Oct 17 02:57:46 2018 +0000

    Fix an issue of default api version
    
    There is a recent change [1] in python-zunclient that breaks the
    zun-ui. In particular, zunclient changes the default api version
    to '1.latest'. Zun-ui directly sends '1.latest' to server which
    result in a 406 response because '1.latest' means client should
    negotiate the api version with server first to decide the actual
    api version to use.
    
    [1] https://review.openstack.org/#/c/608467/
    
    Change-Id: Ib09d2ebb0cd6f4302d6245d10f7790c572614b6a

commit 7ebff515a77be484bbdd6d66624f9e98e97be858
Author: Shu Muto <shu.mutow@gmail.com>
Date:   Tue Oct 16 17:11:34 2018 +0900

    Add hosts panel
    
    This patch adds hosts panel that includes index view.
    
    Change-Id: I1c51961ba33ed4117774df83cad7d5bc6f076f69
    Partial-Implements: blueprint add-host-panel

commit f571466deacbf12a2d02b04d22322a74b95480f4
Author: Shu Muto <shu.mutow@gmail.com>
Date:   Tue Oct 16 16:10:23 2018 +0900

    Add REST API and Angular service for hosts panel
    
    Before implementing hosts panel for admin, this patch adds REST API
    and Angular service for hosts-show.
    
    Change-Id: I4d74d014e1c8185a167343e568a941bb0e29716a
    Partial-Implements: blueprint add-host-panel

commit c922f11b820c2579368fed49d12e928e38db4026
Merge: 4f3be81 87372aa
Author: Zuul <zuul@review.openstack.org>
Date:   Mon Oct 15 05:37:42 2018 +0000

    Merge "Remove unused 'detail' parameter"

commit 87372aa249352d80971733029add225de870938d
Author: Hongbin Lu <hongbin034@gmail.com>
Date:   Sat Oct 13 19:52:27 2018 +0000

    Remove unused 'detail' parameter
    
    This parameter is not used in server and has been removes it from
    client side [1]. This commit removes it from UI.
    
    [1] https://review.openstack.org/#/c/575926/
    
    Change-Id: I39f71d56da51f7c45a5f24da7b535ff570df1bba
    Closes-Bug: #1797528

commit 4f3be81f4cd30f73eac66924d3aaf87f5ca30bcd
Author: Hongbin Lu <hongbin034@gmail.com>
Date:   Thu Oct 11 03:17:00 2018 +0000

    Split command into list
    
    The 'command' parameter has changed from string to list [1].
    This patch updates the UI to catch this up.
    
    [1] https://review.openstack.org/#/c/580990/
    
    Change-Id: I60bdd84c22ba14e0646593a9747c5251e0dd46ff
    Closes-Bug: #1797285

commit ee90370f726a7e84d17cf028acf8996c338e0aa3
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Tue Sep 18 06:50:07 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: I0ca80249d8f1db4dfacf80703e46e704d48f71ae

commit d07126df35cac90c16c1eb6b29be90cdf5956378
Author: Shu Muto <shu.mutow@gmail.com>
Date:   Fri Sep 28 18:03:38 2018 +0900

    Install horizon with upper-constraints.txt in post-install
    
    Change-Id: I3df30cfee88608cd12beaae400b0706446194534

commit ca35ef1d9be065e5b50d5830347d9ba14f1735f6
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Fri Sep 14 06:50:10 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: Icb7888c351dc5b1e0827d17aba901898c1b9d536

commit 9e6e29e32bc5a8715430fb94e4eac5909426ba20
Author: Andreas Jaeger <aj@suse.com>
Date:   Tue Sep 11 21:06:03 2018 +0200

    Cleanup .zuul.yaml
    
    Some cleanups and improvements:
    * Add required-projects to py36 job
    * Use openstack-lower-constraints template instead of individual jobs
    * Sort list of templates
    
    Change-Id: I80992c244a86029d003381d78918e308b08de735

commit eda6db7fcf0f0fe0244a4b702f7f04e99f5dc665
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Wed Aug 29 06:06:05 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: I5c40e986fbca403168c4886b67921342c22aa901

commit b1d899ed541099d2c009b38a7d43f6754d3f794b
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Sat Aug 25 06:17:44 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: I3630aa71c916cb99f33d890089d8fe9c91ea5ac2

commit 8d124776df3498f2e7d2f8a21d56cad4af24bde0
Author: Nguyen Hai <nguyentrihai93@gmail.com>
Date:   Thu Aug 23 00:15:37 2018 +0900

    switch documentation job to new PTI
    
    This is a mechanically generated patch to switch the documentation
    jobs to use the new PTI versions of the jobs as part of the
    python3-first goal.
    
    See the python3-first goal document for details:
    https://governance.openstack.org/tc/goals/stein/python3-first.html
    
    Change-Id: I96e16271dc9eb9a383c12a429380e53ffb7dada3
    Story: #2002586
    Task: #24347

commit 7dc7fe21421c518f6014810ea9457db483d18019
Author: Nguyen Hai <nguyentrihai93@gmail.com>
Date:   Thu Aug 23 00:15:36 2018 +0900

    import zuul job settings from project-config
    
    This is a mechanically generated patch to complete step 1 of moving
    the zuul job settings out of project-config and into each project
    repository.
    
    Because there will be a separate patch on each branch, the branch
    specifiers for branch-specific jobs have been removed.
    
    Because this patch is generated by a script, there may be some
    cosmetic changes to the layout of the YAML file(s) as the contents are
    normalized.
    
    See the python3-first goal document for details:
    https://governance.openstack.org/tc/goals/stein/python3-first.html
    
    Change-Id: I62990e570c756148caa115c5d3b2df7396286408
    Story: #2002586
    Task: #24347

commit a5a7655595df6126f2235986a925afbfb903e6c0
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Wed Aug 22 06:23:32 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: I1ad1ff9f73b0d23e2b8960fc72903db4dfb5f1b8

commit c30b51653e7637453722423d10cafa911882303c
Author: Shu Muto <shu.mutow@gmail.com>
Date:   Wed Aug 22 10:06:10 2018 +0900

    Remove mox3 from doc/requirements.txt
    
    Dependency for mox3 is fully removed. So this patch removes mox3
    dependency from doc/requirements.txt
    
    This should be cherry-picked into stable/rocky branch.
    
    Change-Id: I708b0ac29dc686cec2d16a40281c04e1e61366d3

commit 71573b1b1ae8e799848cc1374fbd2e9283d6d533
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Tue Aug 21 06:23:48 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: I3b72d11937acc31c1ad3cfdfffd24f16d708da36

commit dc8cd20fd598060d256d300ef4f5a6db8405e57b
Author: OpenStack Release Bot <infra-root@openstack.org>
Date:   Mon Aug 20 18:35:33 2018 +0000

    Update reno for stable/rocky
    
    Change-Id: Idddd094d98943f7fa106c8901c6f395572de8584

commit 4cd151ac462dcff5ac9a90dbde63e083aa5b91a1
Merge: 1e1bfdf 205dcd4
Author: Zuul <zuul@review.openstack.org>
Date:   Mon Aug 20 05:44:14 2018 +0000

    Merge "Drop nose dependencies"

commit 205dcd4be9ea3772776b7d03772c50756e9ddc62
Author: Akihiro Motoki <amotoki@gmail.com>
Date:   Fri Aug 17 00:36:47 2018 +0900

    Drop nose dependencies
    
    Horizon test setting no longer depends on nose and related stuffs.
    This commit cleans up nose related dependencies.
    
    The change was made in horizon Rocky-3,
    so horizon 14.0.0.0b3 is required at least.
    
    Change-Id: I616966db07033dded5a6de5e432b5876f015a234

commit 1e1bfdf83e9fa7e34e676e0b5ceb009428f351ae
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Mon Aug 13 06:12:57 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: I5adcbb46aa6bbe2226fd21176238fb7b342439ba

commit 7eb1e0b5dce3c34906cf3f0c048b6b703d3a8fb0
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Sun Aug 12 06:23:24 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: I229295ef697b4959f32faee1f30fb4ba7f4cccc9

commit 2f6ea0b49996f40181c66218467b0e6aa9aceee8
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Thu Aug 9 07:20:41 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: I4661f167cb471d1b7aa90c8b8780c3e0d0d98154

commit 4d24a77d09f7ea499a60045d5d876a6ffb24bb7e
Merge: 605f7b5 7f07dff
Author: Zuul <zuul@review.openstack.org>
Date:   Fri Jul 27 01:01:04 2018 +0000

    Merge "Add release notes for Rocky"

commit 7f07dffe8637c46301fb1e2e55f114a09559c9d0
Author: Shu Muto <shu.mutow@gmail.com>
Date:   Wed Jul 25 13:55:38 2018 +0900

    Add release notes for Rocky
    
    Change-Id: I638f997326a22a184bd45a11d457150c2bf31376

commit 605f7b5d3663ffef130f9a7d5df2465913e11cc8
Author: Shu Muto <shu.mutow@gmail.com>
Date:   Fri Jul 20 10:24:55 2018 +0900

    Prepare to support python3.6
    
    This patch prepares python3.6 support.
    
    We should add py36-local into tox.ini and support for python3.6
    into setup.cfg when we decide to support python3.6 formally.
    
    Change-Id: Ief38d75d7ccea880a7424f18a607bb4c8032568c

commit 7a9eabf7be86e2422250cd98107535e549a0e979
Author: huang.zhiping <huang.zhiping@99cloud.net>
Date:   Sun Jun 10 01:25:36 2018 +0800

    Fix tox python3 overrides
    
    We want to default to running all tox environments under python 3, so
    set the basepython value in each environment.
    
    We do not want to specify a minor version number, because we do not
    want to have to update the file every time we upgrade python.
    
    We do not want to set the override once in testenv, because that
    breaks the more specific versions used in default environments like
    py35 and py36.
    
    To install horizon, check python3 version and set target directory
    in postinstall script on package.json.
    
    Change-Id: Iadf07f630bfc5d8f8d0c2a57e108c0f05aca899d
    Co-Authored-By: Shu Muto <shu.mutow@gmail.com>

commit 29f1efd42e8f3009553ae2b6b64a23cdc2eef5c1
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Wed Jul 18 06:55:54 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: Iaab9eff345176a86fbc3de713a3e78783a80a6a2

commit 34e57e83c463e2ff4f7d3e6d9f62cae073cdf133
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Sun Jul 15 06:28:11 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: I6298ee4706cc31a1fffc2cd86f120609d4928a4d

commit 8cfab7e03e70c6cac710a00042dd9bf0c05cf827
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Thu Jul 12 06:32:00 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: Ie8ce43a222093fdfc75b6dfd5f2940aee5d620fa

commit d801f8cbf39c20d4eb2d0a6716496bed7e51afeb
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Mon Jul 9 06:31:20 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: Ia1fc4d88fb8df867f450d403e27096e315a8ab44

commit 4378273d43abc1f16c5236c8244929c324274a02
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Sun Jul 1 07:03:45 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: Ifaa740dee9f1ef1028e90f0e9fbac42f26fc64e9

commit 15cb9b2fa656101595b5db725548299d6dad57e5
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Thu Jun 28 07:30:35 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: Ic681a4a4db3ce28a0454f26f4b28fdedc9a2223f

commit efd68de685efdcf01216fe38bdfbf4e10fb97947
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Tue Jun 26 06:11:45 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: Idb5d0cd9f9c0823bd8f4191e608ea9a7031d4c7b

commit 582d8b47e13225097c63e24a9f5400312e9b623c
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Fri Jun 22 06:17:05 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: Ib9689e919063d8f38239cb173fadf1fec1dd946c

commit 0444a3886bd5c894e58b14cf1f82e3f0a719d029
Merge: 97a5f97 4a650d7
Author: Zuul <zuul@review.openstack.org>
Date:   Fri Jun 22 03:42:51 2018 +0000

    Merge "Clear selections for table view"

commit 97a5f9757475f68e808deeac1de9bd9654f1fa86
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Tue Jun 19 06:11:08 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: I620c65c4150940b161cf1f0f394cc15fcad6fe43

commit 696492d34f78096151f2e85ca690b5cc69d0302d
Merge: 327f0c9 0a1055d
Author: Zuul <zuul@review.openstack.org>
Date:   Tue Jun 19 03:16:43 2018 +0000

    Merge "Retrieve hosts under initAction"

commit 4a650d7c2502bb6bcaf1cf47b113afee51d3952d
Author: Shu Muto <shu.mutow@gmail.com>
Date:   Tue Jun 19 12:05:13 2018 +0900

    Clear selections for table view
    
    Item selections on table view for batch actions does not be cleared
    after execution of actions.
    This patch ensures to clear item selections by emitting 'hzTable:clearSelection'
    event.
    
    Change-Id: I149a917c39d2892d243dd9fd5b245a8601b43052
    Closes-Bug: #1777545

commit 0a1055dc105a43f1a11cc6dc1a81b67e3cb0b308
Author: Hongbin Lu <hongbin034@gmail.com>
Date:   Sat Jun 16 03:16:07 2018 +0000

    Retrieve hosts under initAction
    
    In before, the UI tried to call Zun API to retrieve the list of
    hosts at the top level. However, if the user is not login, the Zun
    API call will return 401 which causes error on loading the page.
    
    Change-Id: I4af881d38a721a1e70610440e0fba416eab85f41

commit 327f0c9e8c21f536d7d4d83572c40d2951fd16dd
Author: Shu Muto <shu.mutow@gmail.com>
Date:   Thu Jun 14 19:01:20 2018 +0900

    Add delete action for capsule
    
    This patch adds delete action for capsule as batch action.
    Also, adds delete force action as item action.
    
    Change-Id: Iaa27808d55a92f813d4f268ff7cc11cfbc584613
    Implements: blueprint capsule

commit 05e5bb1b99a23a7242558b0c77f0e11574f913dc
Author: Shu Muto <shu.mutow@gmail.com>
Date:   Thu Jun 14 17:57:22 2018 +0900

    Add create action for capsule
    
    This patch adds create action for capsule as global action.
    
    Change-Id: I9ffcc9bcc3118850a174eae0f8afc1dc34b40c34
    Partial-Implements: blueprint capsule

commit 12da76bd2d112a756b0b31cd689b774600411602
Author: Shu Muto <shu.mutow@gmail.com>
Date:   Wed Jun 13 17:16:20 2018 +0900

    Add details view for capsule
    
    This patch adds details view for capsule.
    
    Change-Id: Ia6a46b88aeedaea3642c1d424fedaae65f485655
    Partial-Implements: blueprint capsule

commit 247af4b88b862975c9c79e52565957f723a1e86b
Author: Shu Muto <shu.mutow@gmail.com>
Date:   Wed Jun 13 16:19:20 2018 +0900

    Add capsule panel
    
    This patch adds capsule panel that includes capsule list view.
    Other views and actions will be implemented in subsequent patches.
    
    To enable this panel, copy enabled file[1] to horizon enabled
    directory[2] and restart horizon.
    
    [1] zun_ui/enabled/_1332_project_container_capsules_panel.py
    [2] openstack_dashboard/local/enabled/
    
    Change-Id: I6d89704a8fe4fa32cee52bbf2c38e0b10cd01f1a
    Partial-Implements: blueprint capsule

commit a667cd4bf070efd5437abc3db4031b724eb32b2f
Merge: 45f3116 444c4fa
Author: Zuul <zuul@review.openstack.org>
Date:   Fri Jun 15 01:27:36 2018 +0000

    Merge "Add delete action for images"

commit 45f3116c250e2ba866b760158a80663918380bec
Merge: cb951d6 a2480da
Author: Zuul <zuul@review.openstack.org>
Date:   Fri Jun 15 01:27:35 2018 +0000

    Merge "Add "host" parameter for image pull"

commit cb951d6a81c21c51e1969addc91829670703c75b
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Thu Jun 14 06:28:41 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: Ie1d0190dfca5e9335c8b63a6149a1f46da201b68

commit 444c4faf9014637d85d79d6f1d69b13a35d4014b
Author: Shu Muto <shu.mutow@gmail.com>
Date:   Wed Jun 13 11:24:21 2018 +0900

    Add delete action for images
    
    This patch adds delete action for images panel.
    Delete action needs to specify "host" parameter,
    so this action is implemeted as item action.
    
    Change-Id: I722d2859785ead7175a63d72ab42e1a9e33197ed
    Implements: blueprint add-image-delete

commit a2480da5d34d95860ac0a3b90a412de6dd9b536d
Author: Shu Muto <shu.mutow@gmail.com>
Date:   Wed Jun 13 11:15:59 2018 +0900

    Add "host" parameter for image pull
    
    Also, this patch marks "repo" and "host" as "required".
    
    This patch implements pull-down input for specifying host.
    To compose the pull-down, this patch imlements
    REST API and Angular service for retrieving host list.
    
    Change-Id: Iba8f440f6d8339e1353bb64c26c25a493c874f63
    Implements: blueprint image-host

commit 667f6caf8cc82042d941f093cf27f4dcc100cc35
Merge: ca4371c dba0490
Author: Zuul <zuul@review.openstack.org>
Date:   Wed Jun 13 00:27:15 2018 +0000

    Merge "Add python3 django 1.11 job instead of django 2.0 job"

commit dba0490b24a89cf2cf41487c716a534efe16de22
Author: Akihiro Motoki <amotoki@gmail.com>
Date:   Wed Jun 13 00:16:31 2018 +0900

    Add python3 django 1.11 job instead of django 2.0 job
    
    Django 2.0 is now used in tox py35 job, so there is no need for
    py35dj20 job. Instead, Django 1.11 with python3 is not covered.
    
    - py35dj20 job is dropped from tox.ini.
    - python3-django111 is added to tox.ini.
      python3 is specified to basepython to avoid a specific python version.
    - .zuul.yaml is updated to consume horizon-openstack-tox-python3-django111
      and drop horizon-openstack-tox-py35dj20.
    
    Change-Id: I3f7b2d3398aa482b21a7d10fb98121161d6567bf

commit ca4371c5e3f275b8348bfc22d825f929c817d348
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Tue Jun 12 06:50:58 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: I17f86efe35a33b40a240c3082d5f18687de08b26

commit 513af9dbc359713ad4375abb1792ac1cf74423c8
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Fri Jun 8 06:26:41 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: Ic4550c761f8fcf5f3536ca894948a050369b7e6e

commit 5a1a914960db01a726ae3b869acb14b7a6429c74
Merge: 0c81037 3b037de
Author: Zuul <zuul@review.openstack.org>
Date:   Thu Jun 7 01:36:19 2018 +0000

    Merge "Add rebuild action for container"

commit 0c81037e1e057414b877e54b0ff0c5bce593efdb
Merge: e970171 c125cf6
Author: Zuul <zuul@review.openstack.org>
Date:   Thu Jun 7 01:36:19 2018 +0000

    Merge "Use "update" for container name instead "rename""

commit e97017148e84711f0419300b1a41d9d06c1969a7
Merge: 5be1500 5d2a018
Author: Zuul <zuul@review.openstack.org>
Date:   Thu Jun 7 01:32:41 2018 +0000

    Merge "Add new states for container"

commit 5be150074092d7a286fd4eaeb21044d65f36783c
Merge: 3a0864f 2f01345
Author: Zuul <zuul@review.openstack.org>
Date:   Thu Jun 7 01:31:46 2018 +0000

    Merge "Add new options for container creation"

commit 3b037deebd3aebe65a870d8e97ed2ab7f8618019
Author: Shu Muto <shu.mutow@gmail.com>
Date:   Mon Jun 4 17:32:11 2018 +0900

    Add rebuild action for container
    
    This patch adds "rebuild" action for container.
    
    Change-Id: I68732d40faecfe6ce80c38b8f8b417c0b704a288
    Implements: blueprint build-action

commit 5d2a018b215f864a90497f5be3a63fe04b5e6c03
Author: Shu Muto <shu.mutow@gmail.com>
Date:   Tue Apr 17 17:24:25 2018 +0900

    Add new states for container
    
    This patch applies new container states as follows:
    * DELETING
    * REBUILDING
    * DEAD
    * RESTARTING
    
    Also, update validations for actions.
    
    Change-Id: I42394eb04dcc9a224ccdc230f4773e3531d1306c

commit 2f01345c76e6c819f2b21b2aca6d555edcaab494
Author: Shu Muto <shu.mutow@gmail.com>
Date:   Fri Apr 6 15:12:32 2018 +0900

    Add new options for container creation
    
    This patch adds following options for container creation.
    * auto_heal
    * disk
    * availablity_zones
    
    Also, add these parameters into details views to show.
    And change layouts to add these options.
    
    This change requires python-zunclient 1.4.0 or later.
    
    Change-Id: Ibb9e774ea379a9999c703d6919f14dd0a6e56857
    Implements: blueprint add-params-rocky-1
    Depends-On: I6c0512816277a63bbf444d0775121bb5d964a36a

commit 3a0864fc18bc2e22db3785cadc1fb82fa25d0749
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Tue Jun 5 06:17:16 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: Ie6c8cbeef52ce49e8156ab1e063e2e079b404030

commit c125cf69bf946da8fc45c6540a6ddf1ce28aeb74
Author: Shu Muto <shu.mutow@gmail.com>
Date:   Mon Jun 4 16:44:45 2018 +0900

    Use "update" for container name instead "rename"
    
    This patch uses "update" to change container name instead "rename".
    
    Change-Id: I0c2f4aa2e00ff53b644a849a6e0ace8dbcc7be7c

commit 41fb73489aab72c1669f3fd9307205dc72edc939
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Fri Jun 1 06:34:13 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: I72573a30104e70d973df785d65bd277c2a384ad6

commit fc9fa586fec7a454446be09aaf802c01e136d27f
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Wed May 30 06:32:32 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: I77c067a720365d16298442ab51df74526558fde4

commit 33b1bae56a71cd8e8b8e37749e5d10fd3cfe8d55
Author: Shu Muto <shu.mutow@gmail.com>
Date:   Wed May 30 17:42:43 2018 +0900

    Fix postinstall for npm job
    
    npm jobs uses python3.5, but pip uses python2.7 to install horizon.
    This fixes this issue.
    
    Change-Id: Idc5df31d20def2d29cb1502e5d88946e1be6ae36

commit 34aa9d7ef396ab8a23b9d605807a8e5644222404
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Mon May 28 06:33:40 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: I6cf653581e091678127ec9d86516dc1fc20cb5d4

commit 54dc1d432ac54eae2570af5845b912ecf5f032c0
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Wed May 23 06:29:44 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: I20b0771fc536838f71f363565c7d67188972c553

commit 1cbfca5aba10f8316af24cee956161e58a2b3114
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Sat May 19 06:26:55 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: I5b29ec7830c57572c2af35abc3fccb18f061d53e

commit fde3662a91a056bd0179d72ca198b7cf6b186db7
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Fri May 18 06:35:37 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: I4c9b20358ea7bbaf831f5b69b11972a301dd9482

commit 7000cf788ebeee82986c98958814481f829fc442
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Thu May 17 06:29:13 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: If32839cbb9dec77e55ad3877aa012967c04b72c6

commit 27518980479efc57653589c1f80d0943c24ca2c9
Merge: 4aaaf6e 893b0fc
Author: Zuul <zuul@review.openstack.org>
Date:   Wed May 16 02:12:13 2018 +0000

    Merge "Add py35dj20 job"

commit 893b0fcc4f806e2ebb5e43f9363a096d19a124f2
Author: Shu Muto <shu.mutow@gmail.com>
Date:   Tue May 15 17:02:36 2018 +0900

    Add py35dj20 job
    
    This patch adds py35dj20 job into check/gate jobs.
    
    Change-Id: Ie40db2f90c6659a967212eeb5677e54841b84bdb

commit 4aaaf6e260ec439b44dfb2af2dae28968a19afc5
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Tue May 15 06:29:01 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: Ia8cce6c66a06f3887789e634f3cbb6bf3497180b

commit c4f22c8f2bc6dc4ba98f1661a569aa3a10b935f7
Author: Charles Short <zulcss@gmail.com>
Date:   Thu Mar 22 12:18:47 2018 -0400

    Drop mox3 from test-requirements.txt
    
    Apart of the mox3 community goal for rocky.
    
    Change-Id: Ia9b0ac4af9d963001f546352f40692f2ba115cf2
    Signed-off-by: Charles Short <zulcss@gmail.com>
    Co-Authored-By: Shu Muto <shu.mutow@gmail.com>

commit 0a011691895161caf3dd1974ebb607727381348e
Author: Shu Muto <shu.mutow@gmail.com>
Date:   Wed Apr 18 19:26:37 2018 +0900

    Fix tox jobs and remove tox_helper.sh
    
    Horizon plugins needs horizon on master branch for our
    master development and test.
    
    Recent changes in CI infra and horizon force to change horizon
    installation, and added tox_helper.sh as trivial fix.
    
    Now, reasonable fix found for horizon plugins,
    so this patch fixes them.
    
    Also, use python3.5 for js jobs.
    
    Change-Id: Ibcaf177db21f96e60ee2b222ddd24bc61c3ee9e4

commit 8bdee46fa4d5466582ffcfda2cf9c3b4e8ad95d7
Author: Shu Muto <shu.mutow@gmail.com>
Date:   Fri Apr 20 15:51:57 2018 +0900

    Follow the new PTI for document build
    
    For compliance with the Project Testing Interface as described in:
    
    https://governance.openstack.org/tc/reference/project-testing-interface.html
    
    For more details information, please refer to:
    
    http://lists.openstack.org/pipermail/openstack-dev/2017-December/125710.html
    
    Change-Id: I8f3f9f1ae087b0abd5db0b0f58e83870ca49a529

commit 41d322c45a7e454d4fdf50d17b0c44040a75ecb1
Merge: 50bc369 bb32832
Author: Zuul <zuul@review.openstack.org>
Date:   Mon May 14 06:54:03 2018 +0000

    Merge "Imported Translations from Zanata"

commit bb328329b737f113fdff00a1844ad3563acf0777
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Mon May 14 06:29:15 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: I655a85a7d00bf89be21fa2925f338c348aee71e6

commit 50bc36997d8f109bfd9c355630b5057dc7f4e0ce
Author: Shu Muto <shu.mutow@gmail.com>
Date:   Fri Apr 20 15:04:53 2018 +0900

    Update lower-constraints and requirements
    
    Also, bump horizon to 14
    
    Change-Id: I184d1bfd17b490cd8e078e6c3012480c51db54f0

commit 01a189d8ad76c8a3f539745f4fa2ee01110bd11a
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Wed May 9 06:08:22 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: Ib768c0fa9322a02be68859f3c5750ff0e182c27d

commit bfb7d54123131fced2fa17b517f99a5a28204054
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Thu Apr 26 07:10:52 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: I76ffb054f9011a179a4408394e2af8e02974e5ad

commit c103a8a361ac346ad20b71fd633ab5dcf72f3871
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Tue Apr 24 06:15:37 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: I2ead0764e147507ce165dd3f70c4ce876e89eb4b

commit f183c15eab553dd6d3a96d0dd9a57ecc3aad8ebd
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Sat Apr 21 06:05:04 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: Iabedce540cc79714fe3297b0798cfb494a3350b7

commit 19799fcc49701b8848979a3031027b9fdd5f5d61
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Fri Apr 20 06:09:28 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: I4c990fb991d7bb97ac0be539f5ffc2934c419e8a

commit 7af04961e563538a79a1e1be785e09454207ebe8
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Thu Apr 19 06:06:07 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: I18bf82e5d36a394087df3cc8eaa2f17b8716a017

commit 4d7dcaa3ddba7111f15a021d2b83fa5328a11610
Merge: ad6898f 3f01ef2
Author: Zuul <zuul@review.openstack.org>
Date:   Thu Apr 19 05:20:27 2018 +0000

    Merge "Add Manage Security Groups action for container"

commit ad6898f17a408f2417fd15181901df152f00ea03
Author: Shu Muto <shu.mutow@gmail.com>
Date:   Wed Apr 18 15:51:47 2018 +0900

    Suppress resize error on resizing browser
    
    This bug seems to be due to rare situation, so we could not identify
    the reason for now.
    But this bug occurred when cloud-shell.controller is missing container ID.
    If this bug occur, the toast popups so many and they are so obstacle.
    So this patch changes cloud-shell.controller to ignure the resize event
    when container ID was missing.
    
    Change-Id: I598c11c9fb2086e7e001b70df8de57968d6d13db
    Closes-Bug: #1764953

commit 57f3e6a94debd567efc5ffef19ab276725a57463
Merge: 69ecf1c 1d47c36
Author: Zuul <zuul@review.openstack.org>
Date:   Wed Apr 18 05:44:09 2018 +0000

    Merge "Suppress conflicts between retry options and auto_remove option"

commit 3f01ef2f6ed7782b1d269fd7708bc798ed8aef45
Author: Shu Muto <shu.mutow@gmail.com>
Date:   Fri Apr 6 15:12:32 2018 +0900

    Add Manage Security Groups action for container
    
    This patch adds "Manage Security Groups" action as item action
    for the container. This action manages the associations
    between port and security group.
    
    Change-Id: Ic39a985c7daffdb7f5e5616a0eb3c07d57c4db22
    Implements: blueprint manage-security-groups

commit 1d47c368fe4ef5f8ef360296dd1ed4fc149f0b7e
Author: Shu Muto <shu.mutow@gmail.com>
Date:   Wed Apr 11 16:30:52 2018 +0900

    Suppress conflicts between retry options and auto_remove option
    
    This patch fixes conflicts between retry options and auto_remove option.
    To suppress this conflicts, when retry option selected this patch clears
    auto_remove option and set readonly attribute for the checkbox.
    
    Also, to check them easily from user, move auto_remove option from
    Miscellaneous tab to Spec tab, i.e. under retry options.
    
    Change-Id: I34a409141adf1ad822e5999240ccbb8ae8e2acf5
    Closes-Bug: #1763250

commit 69ecf1c8dac9e2d0d034057ec7edc63187772cec
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Sat Apr 14 06:04:33 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: I6038894050e2f75ac6e7829a938b20873f5d89fb

commit 3f7935d3ac22b31a1eb103a12988756618f742f9
Merge: 1fb13fe 8d9571a
Author: Zuul <zuul@review.openstack.org>
Date:   Fri Apr 13 12:32:51 2018 +0000

    Merge "Clean-up tox"

commit 8d9571ab6f2d2174ffaf418f06dafabc2109d210
Author: Shu Muto <shu.mutow@gmail.com>
Date:   Fri Apr 13 17:42:09 2018 +0900

    Clean-up tox
    
    To simplify tox.ini, move processes for cleaning-up env and
    installing horizon from git into tools/tox_helper.sh.
    
    Change-Id: I6b3d66869ef3958c311dae57333c3e557207aa13

commit 1fb13fefcb630b51b5759462887dc5fe57786a35
Author: Shu Muto <shu.mutow@gmail.com>
Date:   Wed Apr 11 16:05:05 2018 +0900

    Describe more about security group on create
    
    This patch adds description for security group on container creation dialog.
    
    Change-Id: Idb019f9956aefca275d7554e4eff203b7a2724f8

commit bd0b01d86ff5d56e91f7d966424851d04e830e5d
Merge: 0158ec8 da21388
Author: Zuul <zuul@review.openstack.org>
Date:   Mon Apr 9 06:49:29 2018 +0000

    Merge "Reproduce navigations"

commit 0158ec88326107eebd23709c3784dd2bea561f94
Merge: 6982fea 6f4827b
Author: Zuul <zuul@review.openstack.org>
Date:   Mon Apr 9 03:07:46 2018 +0000

    Merge "Present container deletion better"

commit 6982fea9314ce59fcfeacca901717e877827a9fe
Merge: 2c5ac57 21187bb
Author: Zuul <zuul@review.openstack.org>
Date:   Mon Apr 9 03:07:46 2018 +0000

    Merge "Fix the error on 'stop and delete container'"

commit 2c5ac5766812ed7a5a85bd08285e8a3a54a2355f
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Sun Apr 8 07:25:56 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: Ieacc77223ec8a44c2079accf2e2d4cb0a220410c

commit 6f4827bea65134f152a85980bbe0a0accc0c26ce
Author: Hongbin Lu <hongbin034@gmail.com>
Date:   Sat Apr 7 21:42:12 2018 +0000

    Present container deletion better
    
    Zun server has changed from synchronous deletion to asynchronous
    deletion. This mean Zun accepts a request to delete a container
    but the container is not deleted right away. In the UI, it is
    better to present the container in 'deleting' state instead of
    removing the container from displaying.
    
    Change-Id: I05c64a1388356887aba19dc94f27dbbd0d0bcc02

commit 21187bb0a83791217e69d7cd29aba70722da20e2
Author: Hongbin Lu <hongbin034@gmail.com>
Date:   Sat Apr 7 20:58:35 2018 +0000

    Fix the error on 'stop and delete container'
    
    Change-Id: I0bb027d175c752a9a0980f4cbf2ebd688e7e2977
    Closes-Bug: #1762068

commit b49c32def392b91169d476a3d90a5336b8ab61e5
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Fri Dec 8 16:38:34 2017 +0900

    Add networks tab for container update
    
    This patch adds "Networks" tab into container update dialog
    to attach/detach networks.
    
    Change-Id: I32e3892edfb14a81948a97d3182c1066850655a8

commit 40c8cf531c354e767754aeebaae32a61c3026f0d
Merge: 09080e0 94d15f9
Author: Zuul <zuul@review.openstack.org>
Date:   Thu Apr 5 00:09:50 2018 +0000

    Merge "Install Horizon from git repository in tox test"

commit da213880dca759baa7405440a8d95bc82e5fdda5
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Mon Aug 7 14:59:05 2017 +0900

    Reproduce navigations
    
    Details view does not reproduce side menu and breadcrumb properly
    by refreshing or linking directory.
    This patch fixes this issue.
    
    Change-Id: I13d9c8381a429caf7e7f4c984a7128faa764ad12
    Closes-Bug: #1746706
    Depends-On: I2edd44e55eb10114e5282cec1762e9635881f733

commit 09080e087d3c394eb9baeb2b09d0014713d5f7b6
Author: Shu Muto <shu.mutow@gmail.com>
Date:   Thu Mar 29 16:36:01 2018 +0900

    Add releasenotes links to README
    
    Add release notes link to README.rst.
    
    Change-Id: I209065a0ebbd7c040d0651961abc75a961bab837

commit 94d15f9eede572bdb04f67120ebb53f535725e96
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Thu Mar 29 11:10:08 2018 +0900

    Install Horizon from git repository in tox test
    
    To test UI plugins, we should install recent Horizon
    from master branch like CI infra does.
    
    Also, this patch adds new testenv:py35dj20, due to
    Horizon has plan to bump Django version to 2.0.
    
    And new testenv:jstests for eslint and karma is added.
    
    To run tox test easily before upload patchset,
    adds py35dj20, jstests, docs and releasenotes to envlist.
    
    Change-Id: I9f111c1d2a70e87f60e9901e6070d05e3dc1a76d

commit 67a7aafe845357762ff02a5b2b8fe246c33e7b4e
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Wed Mar 28 09:30:05 2018 +0000

    Updated from global requirements
    
    Change-Id: I74d4f1d2346ce024c7b402e53581888ac8a2b212

commit 776a65e5db95f0bf206d4a09b9c5b081b9887e3c
Merge: 6b601ba d53c591
Author: Zuul <zuul@review.openstack.org>
Date:   Mon Mar 26 00:55:21 2018 +0000

    Merge "add lower-constraints job"

commit d53c591e5f59edb9d887fb34ec79524159bf5caa
Author: Doug Hellmann <doug@doughellmann.com>
Date:   Thu Mar 22 19:19:04 2018 -0400

    add lower-constraints job
    
    Create a tox environment for running the unit tests against the lower
    bounds of the dependencies.
    
    Create a lower-constraints.txt to be used to enforce the lower bounds
    in those tests.
    
    Add openstack-tox-lower-constraints job to the zuul configuration.
    
    See http://lists.openstack.org/pipermail/openstack-dev/2018-March/128352.html
    for more details.
    
    Change-Id: Id6c04604ad9f51aadd233f21f99ddce21c3d8980
    Depends-On: https://review.openstack.org/555034
    Signed-off-by: Doug Hellmann <doug@doughellmann.com>

commit 6b601badd8cb720e207549ac73018a1e198183a7
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Thu Mar 22 10:17:01 2018 +0000

    Updated from global requirements
    
    Change-Id: Ib0eb5de22bb3e068b194f2cb535789e50205721a

commit 748b2de3c4e8d56d890034bca37ec2bfd17fdfa7
Author: wangqi <wang.qi@99cloud.net>
Date:   Tue Mar 20 09:04:02 2018 +0000

    add documentation link to README
    
    Change-Id: Idbb7cb25ffb6a771a29320fa9b5e7d71b5dfeb2d

commit 2766e091a8888d2e6f42421b67b57b9db127ecf6
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Fri Mar 16 07:15:08 2018 +0000

    Updated from global requirements
    
    Change-Id: I52e1c7e1a1a02c42c54465e427b7658140cceaaa

commit 9bf92c5c855e052accffe5d6bdce5d18bd8e8e97
Author: Hongbin Lu <hongbin034@gmail.com>
Date:   Fri Mar 16 03:36:52 2018 +0000

    Install horizon directly from pypi
    
    It's no longer possible to install horizon with our current
    method, and it's causing the ci to fail.
    http://lists.openstack.org/pipermail/openstack-dev/2018-March/128310.html
    
    Depends-On: Iad46a2b63a9fd1b116f89c8084202a08faa0ab05
    Change-Id: I919fa31df50c80d1d2fbf73eafddedefa475cac1

commit 9ab56ba9b16dc48697a73a44652c900413b497d2
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Tue Mar 13 07:39:45 2018 +0000

    Updated from global requirements
    
    Change-Id: I50564ada719b359ddf7154a55439141e55edaaef

commit 17be328485d9b70f7d1842be60193cc9239d00db
Merge: f60016b 7d8f15a
Author: Zuul <zuul@review.openstack.org>
Date:   Mon Mar 12 01:21:20 2018 +0000

    Merge "Imported Translations from Zanata"

commit 7d8f15ae4b88ad5f30b21af6a5fde91a8b260fae
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Sun Mar 11 07:16:09 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: Id37e6e2d2aed70b5a01631054e3c1df660f413f9

commit f60016b4f7a2c8b4556c9cd8f39bae64fd2e6290
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Sat Mar 10 14:01:47 2018 +0000

    Updated from global requirements
    
    Change-Id: Ic83d1f6f85bf540a4796b289c90f9eff2592f22d

commit c6fcba6a0eb583665e8957d84ec817f7ee79974d
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Thu Mar 8 07:20:15 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: If7bbe2c9180f7c4e1d6a87d7b9e0c0f6b1612418

commit 5b04304bbc12059abc5a80d17cfc418a94c7a01a
Merge: de02185 6feb702
Author: Zuul <zuul@review.openstack.org>
Date:   Wed Mar 7 17:07:43 2018 +0000

    Merge "Imported Translations from Zanata"

commit de021853dbca376e7e980286b7ce47e238e14a99
Merge: b05f1d1 288c26a
Author: Zuul <zuul@review.openstack.org>
Date:   Wed Mar 7 17:03:53 2018 +0000

    Merge "Change runtimes to accept string"

commit 6feb702a6ee199fd92d4ebe058907d42447be4e0
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Wed Mar 7 07:17:32 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: Ib51ef0ceb56cbff159b6124c7355883abe5c5efd

commit 288c26aad11e989520a21276cf187caedd2eeb7b
Author: Madhuri Kumari <madhuri.rai07@gmail.com>
Date:   Mon Mar 5 04:59:24 2018 -0500

    Change runtimes to accept string
    
    Currently the runtime is a drop down menu with only
    "runc" option. User is not able to enter new runtimes
    configured by them. So this patch changes the field to
    accept any user input string for runtime.
    
    Change-Id: I5e60dd782b799c013a492f823f144cfbe5fdfc15

commit b05f1d1094d2c38c12380bbf16b5e90f70b9faff
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Thu Mar 1 07:25:41 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: Ifca8545bccab69eb05a15bf2c79bcb99ce42b50e

commit 23d054e1ded936f85b751cd81ee1b25ac9272b08
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Tue Feb 13 07:08:06 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: I4fb3215bbbfed4c048653389bf026c25083d0346

commit 349c25dd3a13a016340b565dd23ca36820404e65
Merge: 4e69df8 67d6440
Author: Zuul <zuul@review.openstack.org>
Date:   Tue Feb 13 03:51:41 2018 +0000

    Merge "Increase the memory step size to 128M"

commit 67d6440509f543704baa3d4dd84d252395133ffb
Author: Hongbin Lu <hongbin034@gmail.com>
Date:   Fri Feb 9 03:02:47 2018 +0000

    Increase the memory step size to 128M
    
    The default step size is 1M which is too small.
    
    Change-Id: Ic81e7cbaf9f51f139c5b09ecf00aa133d1e603e0

commit 4e69df85f8195d312dc57a548e0965511cf998dc
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Wed Feb 7 06:26:59 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: Ic48a5c7b950f66af2e3f91f2cdca1adbf731371c

commit c23884db557ec367d7c5122c2f595038482c226b
Author: OpenStack Release Bot <infra-root@openstack.org>
Date:   Mon Feb 5 23:19:27 2018 +0000

    Update reno for stable/queens
    
    Change-Id: Ia53ec0824b4174e9fccd5d6cf9cb3f7a3ca56bb9

commit 25067d3004ef964cd037f33dfadb7fd52d64a19c
Merge: 63f24b8 e7418c2
Author: Zuul <zuul@review.openstack.org>
Date:   Mon Feb 5 07:51:59 2018 +0000

    Merge "Add gettext for Volumes tab"

commit 63f24b842b0f5c529487ebba026975f256f0d25c
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Mon Feb 5 06:36:33 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: Id3d438569ed07751f3fef102cf2ceb5882c44473

commit e7418c22c85cc4353f667c52c5edd8a2e0f9ab11
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Mon Feb 5 14:34:20 2018 +0900

    Add gettext for Volumes tab
    
    Change-Id: Ifa5778943f0327e4f5f2a18782d8fbce03296b67

commit 40f82d3484a61db22832dbe169085ae3c30415af
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Wed Jan 31 16:57:51 2018 +0900

    Add release notes for Queens
    
    Also, fix docs for cloud shell, comments on the source code
    and title of help item for runtime.
    
    Change-Id: I90e175bdd7310e9052540948abe05e77e918a54c

commit e7dbe2f1e083f57aacb9fd386e048680095e4dcf
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Wed Jan 24 01:43:26 2018 +0000

    Updated from global requirements
    
    Change-Id: I82c062dd30718d326797ab685e10c4e0d9871f77

commit e69bffc44d5cde8e062e62b2f60d6587f83ff977
Merge: 416e698 1ee4356
Author: Zuul <zuul@review.openstack.org>
Date:   Mon Jan 22 00:55:20 2018 +0000

    Merge "Updated from global requirements"

commit 416e6984b8bf78699fb2d59bc85fce0c811f0822
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Sat Jan 20 06:50:38 2018 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: I23bae4d700d073643a8abb904e3b2d5a39ae571a

commit 1ee4356a823f1acd3131db34da6bfc0ac1c6413a
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Fri Jan 19 12:55:35 2018 +0000

    Updated from global requirements
    
    Change-Id: Id1879c660de01baa3172082695a865f3a08633a1

commit 17c720878f1df4c59d95109d8e453b2249a2c3f4
Merge: 18ad8fb 9f45851
Author: Zuul <zuul@review.openstack.org>
Date:   Fri Jan 19 07:17:36 2018 +0000

    Merge "Add Cloud Shell feature"

commit 18ad8fb1988bb40f8ff968c88039e1dc5a18d7c6
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Thu Jan 18 03:40:23 2018 +0000

    Updated from global requirements
    
    Change-Id: Idc0201e0a9072bebb42b4234fbf542567d501399

commit 5fcf0d8c4bbcfc25e2d7087e0f19e5bfa6cedaa3
Author: chenpengzi <1523688226@qq.com>
Date:   Mon Jan 15 10:36:04 2018 +0800

    Change the wiki address to docs links
    
    Change-Id: I0e7cd16522061a002601b2e7d1d4b0d92156fa63

commit 13e0a598635dbd43f0608779f4aca7e256fe4008
Merge: 34f2334 a9c0984
Author: Zuul <zuul@review.openstack.org>
Date:   Sat Jan 13 08:00:13 2018 +0000

    Merge "Fix issue the deleted item is selected again with batch delete"

commit a9c09849095e66798ba797f096a91e23c481053b
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Thu Jan 11 12:15:49 2018 +0900

    Fix issue the deleted item is selected again with batch delete
    
    Items recently deleted with batch action are shown in deletion
    confirmation dialog when execute the batch delete action again.
    
    Steps to reproduce:
    1. Create 2 new items
    2. Delete one of them using the batch delete action on top of the table
    3. Select the another item and click the batch delete action
    
    Expect to see the confirmation dialog shows one selected item,
    but it shows the item that was deleted in step 2 as well.
    Also, HTTP DELETE method for already deleted item is submitted
    again and occurs error.
    
    This patch fixes this issue.
    
    Change-Id: I5940b3b073d5bb9273068c22e090e3af390c9792
    Closes-Bug: #1742599

commit 34f23346eb251f1f2ed792c513f5ebbe52e6e325
Merge: efa2b2c 3ca02e3
Author: Zuul <zuul@review.openstack.org>
Date:   Thu Jan 11 03:23:48 2018 +0000

    Merge "Add Volumes tab for container creation"

commit 3ca02e37459d106a931bd09dd03498ac6fe42187
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Mon Dec 11 18:32:54 2017 +0900

    Add Volumes tab for container creation
    
    Change-Id: I592a7cc048ef78a72685d0f67603d864734423f5
    Implements: blueprint cinder-integration

commit efa2b2c8e578a41e6831c324fe58957230aa6bb4
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Wed Dec 27 16:57:19 2017 +0900

    Add project_id for image
    
    This patch adds project_id for image into index view.
    
    Change-Id: I3ed29aa252c839b058c2f1f4db1e213f5155f031

commit 9128058061f5306a91ed4b828d6248dd5d29362c
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Tue Dec 19 06:07:06 2017 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: Ib776083944ae740b4a0349ca3fbf5935d8b6c780

commit 9fee717602bd61d38b5a118b953cb3549d27dc11
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Wed Dec 6 15:17:54 2017 +0900

    Stop container before deletion
    
    When container is running, stop the container before deletion.
    
    Change-Id: I940c36d47070be213c376f8140300aa3e10bbf02

commit a4cb8d1f24ea7ff29c384f2af88c3fbfcfb0464d
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Tue Dec 5 20:44:49 2017 +0900

    Add parameters for container creation
    
    This patch adds 'auto_remove', 'hostname' and 'runtime' parameters
    for container creation. Also, adds these parameters into details
    view. These parameters are not for update, so these are readonly
    in update dialog.
    
    Change-Id: I011008023158dabf6f69b3b1695d6ed3eaed849d
    Implements: blueprint add-create-options-for-queens

commit 20c1196e2c1d6b79e5da2a4c777a306d7eb29044
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Wed Dec 6 12:11:30 2017 +0900

    Update packages for JavaScript tests
    
    This patch updates packages for JavaScript tests.
    Also, adds '.idea' directory for PyCharm into .gitignore.
    
    Change-Id: I83c3a5474a38b14aa0e6f73fd7ee91216717a4a4

commit 830ff17072906518283d995420145551b6d4e2ca
Merge: 01d2c63 c5c15a8
Author: Zuul <zuul@review.openstack.org>
Date:   Mon Nov 20 04:48:38 2017 +0000

    Merge "Updated from global requirements"

commit 01d2c63ef9dc7227d32339a246c72bfa5a720de7
Author: Andreas Jaeger <aj@suse.com>
Date:   Thu Nov 16 20:56:59 2017 +0100

    Remove setting of version/release from releasenotes
    
    Release notes are version independent, so remove version/release
    values. We've found that projects now require the service package
    to be installed in order to build release notes, and this is entirely
    due to the current convention of pulling in the version information.
    
    Release notes should not need installation in order to build, so this
    unnecessary version setting needs to be removed.
    
    This is needed for new release notes publishing, see
    I56909152975f731a9d2c21b2825b972195e48ee8 and the discussion starting
    at
    http://lists.openstack.org/pipermail/openstack-dev/2017-November/124480.html
    .
    
    Change-Id: I8751bfb45727c45c03b50bfe0ba10a67b4dbe36b

commit c5c15a8653f88901e76c331e3d2b4a41e4a2bc24
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Thu Nov 16 11:32:04 2017 +0000

    Updated from global requirements
    
    Change-Id: I8feaa3775856401f79c47355677b234b6eaf7446

commit 7b3ac8567d4fd9a9770d4fbf99a1299d657eef88
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Thu Nov 16 06:35:30 2017 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: Iad6cb35d5ea5bd157a617d69b58cde06a8b97874

commit 4beb783bc255fdf468028ef042432285db220fbc
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Wed Nov 15 14:17:12 2017 +0900

    Fix URL of help html template for kill signal action
    
    This fixes URL of help template for "Send kill signal" action.
    
    Change-Id: I3be327cfc1c3c1fd18d1ed5fc479e6e55cf266c0
    Closes-Bug: #1732340

commit 9341dfa053cf3376c987e9f392dcbbcb91b15d51
Merge: 53b5f0f 6141ad6
Author: Zuul <zuul@review.openstack.org>
Date:   Wed Nov 1 05:57:27 2017 +0000

    Merge "Cleanup tox and requirements"

commit 6141ad62ac0ed26520427dedc6609df88d2a938f
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Fri Oct 27 17:02:18 2017 +0900

    Cleanup tox and requirements
    
    Remove unnecessary requirements and exclusions for flake8.
    
    Change-Id: I80a41847cae36eb66dd6ce621a10ba273d8ec276

commit 9f458518593d5f0f7a3d620f8785720a8efc270d
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Tue Oct 17 12:46:12 2017 +0900

    Add Cloud Shell feature
    
    Screen Shot:
    https://drive.google.com/file/d/0B1UFZO9xX8eweERNX2FWVGRrMXM/view
    Short Video:
    https://youtu.be/lYt2U7qZG38
    
    This patch realizes the Cloud Shell feature as following manner:
    
    1. Add 'Cloud Shell' menu on the top menu bar.
    2. When 'Cloud Shell' menu clicked, create console area on
       the bottom of window.
    3. If cloud shell container does not exists for the user,
       create the container.
    4. If cloud shell container exists, attach the console area
       to the container.
    5. Each time when attach to the container, clouds.yaml will be
       exported into the container.
    6. Password will be not imported into the container,
       so user should set manually 'OS_PASSWORD' into envirinment
       variables or 'password' into clouds.yaml.
    
    Change-Id: Ia26be196758e5f3617b31750702a6c54436efb93
    Depends-On: Ie4bc4d7302ce80ed9925db4156ff52f928460aca

commit 53b5f0fcef6651571b4c2d0526403bf20550ad5d
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Mon Oct 9 10:43:35 2017 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: Ie5f3e788f34795029e788bbbb03cade7edbec7b6

commit 0a73c0d90fb9715547e33f0b60b4f533522df541
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Thu Sep 21 03:53:07 2017 +0000

    Updated from global requirements
    
    Change-Id: I8a9b516dfd1ca76163c818b348ecd6efc01f8af5

commit f74c6fe709dce7434d7981fafce56a63dd6b2aaf
Author: rajat29 <rajat.sharma@nectechnologies.in>
Date:   Tue Sep 5 12:35:51 2017 +0530

    Fix to use . to source script files
    
    Adhering to coding conventions. Refer to ``Code conventions`` at
    https://docs.openstack.org/contributor-guide/ for details.
    When you have to source a script file, for example, a credentials file
    to gain access to user-only or admin-only CLI commands, use . instead of source.
    https://docs.openstack.org/contributor-guide/writing-style/code-conventions.html
    
    Change-Id: Ibe6a0a8eda9214d76b6420f5a9d6d233133ee6d2

commit aeee17c10cc506d368c45ebfffac29e078841aac
Author: Xing Zhang <zhangxing@unitedstack.com>
Date:   Fri Sep 1 15:52:33 2017 +0800

    Update and refactor zunclient
    
    I do two things on this patch:
    [1] update params in zunclient
    [2] refactor params in zunclient by usingi memoized_with_request
    
    python-zunclient v1 api refactor client and remove or rename
    parameters:
    removed zun_url by using endpoint_override instead
    input_auth_token was renamed to auth_token
    and zun-ui was using the old params, listing images and containers
    on horizon will raise error like:
    MissingRequiredOptions: Auth plugin requires parameters
    which were not given: auth_url
    
    Change-Id: I6e54981057bad877317ca19d049b8b071394f556
    Depends-On: Ie9be389495e2f13454f1f8d1c1d66b22d813a9ec

commit a51944b2b4772f93081975c69419bda403b7461a
Merge: d1d78cc 2c67023
Author: Jenkins <jenkins@review.openstack.org>
Date:   Tue Aug 29 05:51:56 2017 +0000

    Merge "Imported Translations from Zanata"

commit 2c670231b5a5d496335aa8e6689f9b9767c9d3fe
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Mon Aug 28 10:20:19 2017 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: If853aa9e443032ed25c68c083ebf56e7b780ec53

commit d1d78cc1b0a852448a46eb0db5cf19d550b54c44
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Fri Aug 25 10:18:32 2017 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: I17e17f3fa05cb7c5370d63b854b520321531e8a8

commit 90783a84b83918084a159263465d7b2c8a9c569f
Merge: 09b6d54 c5436a9
Author: Jenkins <jenkins@review.openstack.org>
Date:   Tue Aug 22 02:37:27 2017 +0000

    Merge "Imported Translations from Zanata"

commit 09b6d54dd2a39f63d13507f8034cd6db5956e4e4
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Tue Aug 22 00:50:18 2017 +0000

    Updated from global requirements
    
    Change-Id: I7347f0a5ab5a0becbf20e52387c4061c9504a5d5

commit c5436a9cf42405ba3520c861b6c5498a0e1356e9
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Sun Aug 20 10:11:49 2017 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    https://docs.openstack.org/i18n/latest/reviewing-translation-import.html
    
    Change-Id: I455697fec4f25596f0a4194ca49bd2d94be8a0ee

commit be8daba64bdafdf866a1f5f632815ffe442b64ba
Merge: 72ede7b 0b0aceb
Author: Jenkins <jenkins@review.openstack.org>
Date:   Sun Aug 20 05:55:14 2017 +0000

    Merge "Show actions according to container status"

commit 72ede7bf61f2c6195ec7250b091acd129dd0d440
Merge: e6b135c 0941736
Author: Jenkins <jenkins@review.openstack.org>
Date:   Sun Aug 20 05:54:51 2017 +0000

    Merge "Update reno for stable/pike"

commit e6b135c0771b0296bd3ddf4d3b934c92f11e905a
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Sat Aug 12 10:23:29 2017 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    http://docs.openstack.org/developer/i18n/reviewing-translation-import.html
    
    Change-Id: I8cc043dbf186a6d340680e8c76cd73676fcb5b36

commit 09417367c3e175dbe9c94120cd095feb5f31306f
Author: OpenStack Release Bot <infra-root@openstack.org>
Date:   Fri Aug 11 20:48:54 2017 +0000

    Update reno for stable/pike
    
    Change-Id: I5ba12abf12115d73d132f9477f186ba4bc82e8eb

commit 0b0aceb5c818248d6ade80de368db4f42772b843
Author: jiangpch <jiangpengcheng@navercorp.com>
Date:   Wed Aug 9 04:23:54 2017 -0400

    Show actions according to container status
    
    Now the ui will show all of the actions regardless of container's
    status, while the zun_api will check it and return a 409 code if
    status is not valid, we should filter the actions just like what
    nova instances do
    
    Change-Id: Id87ec80238b407f1475c83303f6a5cab57e07385

commit 7561c1b6aed9399980da3f9560e968b3dc97bc6a
Merge: 2d6013d a33e2c4
Author: Jenkins <jenkins@review.openstack.org>
Date:   Tue Aug 8 14:17:26 2017 +0000

    Merge "Fix container deletion error"

commit 2d6013d96cb11841deb3765726f9384a1a4e7f23
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Mon Aug 7 10:28:58 2017 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    http://docs.openstack.org/developer/i18n/reviewing-translation-import.html
    
    Change-Id: Ib6d06ee2cc223a50455b7ea55400738395839ee0

commit a33e2c43595342c557a837fa7f9ba63612f22ccc
Author: jiangpch <jiangpengcheng@navercorp.com>
Date:   Mon Aug 7 02:40:24 2017 -0400

    Fix container deletion error
    
    Change the argument `force` to a keyword argument as the delete
    method of zunclient's container doesn't accept a `force` argument.
    
    Closes-Bug: #1709009
    
    Change-Id: I98283c93aef0ce9bda8395f9db9fdbc0b3664dbc

commit 3056b26a548e32df0a026b1d391a3606124d4782
Merge: 25a092f eb579c4
Author: Jenkins <jenkins@review.openstack.org>
Date:   Mon Aug 7 01:46:40 2017 +0000

    Merge "Revert "Enable to refresh details view""

commit eb579c450020868177a29927dba64a8c4df8ef9d
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Mon Aug 7 01:22:53 2017 +0000

    Revert "Enable to refresh details view"
    
    This reverts commit 7bee55d9258c67de922c656e2428522c6f9b36da.
    
    Change-Id: I5806a3923bc8bed37dafd24d1ccef7486d4a06f3

commit 25a092f5189adf3bf1f53b0e9a43cdcf198a6c48
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Thu Aug 3 10:36:56 2017 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    http://docs.openstack.org/developer/i18n/reviewing-translation-import.html
    
    Change-Id: Iff2b3f49a73deca3252e1d07e8d79e779a2ccbb2

commit bb6290ee14ea5cd46a467fde5d9b08f949999e27
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Mon Jul 31 11:36:05 2017 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    http://docs.openstack.org/developer/i18n/reviewing-translation-import.html
    
    Change-Id: I8ae6f1839d46da3b10b34476017169c2557db796

commit 58b554daf235b676f960a5cab401be1b18951ebb
Author: Andreas Jaeger <aj@suse.com>
Date:   Sun Jul 30 10:01:32 2017 +0200

    Fix invalid UTF-8
    
    Current translation sync fail with:
    UnicodeDecodeError: 'ascii' codec can't decode byte 0xc2 in position 3:
    ordinal not in range(128)
    
    Example:
    http://logs.openstack.org/periodic/zun-ui-propose-translation-update/2f95b23/
    
    The problem are two wrong " " UTF-8 characters, replace them with ASCII
    ones.
    
    Note that the diff will not show this as real difference. But comparing files before and
    after using "file" shows before: UTF-8 Unicode text
    And now: ASCII text.
    
    This was introduced with change I2eba1ac77deec797342fc1adff60f45e8ea0a70f.
    
    See
    http://status.openstack.org/openstack-health/#/job/zun-ui-upstream-translation-update
    for when the failures start.
    
    Change-Id: Idd443c3a432c78374f6d10d48f759ff5787e439c

commit 72b5ea6c07e5ba6680bf11c8acd47d85b2a68553
Merge: c03492a 7bee55d
Author: Jenkins <jenkins@review.openstack.org>
Date:   Sat Jul 29 11:29:28 2017 +0000

    Merge "Enable to refresh details view"

commit c03492a3f39519a6e6d06f374156d8bf6abe691d
Merge: 51c16f5 01f1d12
Author: Jenkins <jenkins@review.openstack.org>
Date:   Fri Jul 28 05:14:03 2017 +0000

    Merge "Updated from global requirements"

commit 51c16f56958221473924d9f0955f9ff9d3cdb10e
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Fri Jul 28 13:37:16 2017 +0900

    Fix help string for network setting
    
    This patch fixes help string for network setting on create
    container dialog.
    
    Change-Id: Ic9672c53243c4fc01adbbc0e39c91d44e2fdaca7

commit 01f1d1200ed9912f525cd92840f3117eff583589
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Fri Jul 28 02:51:44 2017 +0000

    Updated from global requirements
    
    Change-Id: I6f97c0663ceb00a27f84da8556e906712937ec2e

commit a8fe662dd8d817125b2554cf8c7ea4ca8ba0b4ee
Merge: 6881b6a 8c4b598
Author: Jenkins <jenkins@review.openstack.org>
Date:   Fri Jul 28 01:28:53 2017 +0000

    Merge "Add release notes for Pike"

commit 8c4b5988cffa19f30f3488a6e77cad64d40aa8e7
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Mon Jul 24 16:46:06 2017 +0900

    Add release notes for Pike
    
    This patch adds release notes for Pike.
    
    Change-Id: I1650fce3c1b7711de53d7626684c26b65f551d40

commit 6881b6ad4fa819231d493812bdd3b17a6085977e
Merge: aa88f30 45750bc
Author: Jenkins <jenkins@review.openstack.org>
Date:   Fri Jul 28 01:02:32 2017 +0000

    Merge "Add Networks and Ports step for creation dialog"

commit 45750bc889143389e0cd922de1c208641d5491eb
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Wed Jul 26 16:06:27 2017 +0900

    Add Networks and Ports step for creation dialog
    
    To specify nets option when create container, this patch adds
    Networks and Ports steps into the creation dialog.
    
    The Networks and Ports steps are not shown in update dialog.
    
    Change-Id: I686e603d43b67648df08af398a550069f5087415
    Implements: bluepring add-network-step

commit aa88f301703a8d7c16d8b377cfa7515e9ab3f425
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Thu Jul 27 22:38:39 2017 +0000

    Updated from global requirements
    
    Change-Id: I1f5c3d5252fa7037906caa28a18eeb987f7a7f30

commit 88cca7d35d85d772bd7bcea0920d7a6d7e88e96e
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Tue Jul 25 17:19:02 2017 +0900

    Add Scheduler Hints step into creation dialog
    
    To specify scheduler hints options when create container,
    this patch adds Scheduler Hints step into the creation dialog.
    
    The Scheduler Hints step is not shown in update dialog.
    
    For now, only Label Filter is available. So there are no
    scheduler hint definitions in the left column.
    
    Change-Id: I2eba1ac77deec797342fc1adff60f45e8ea0a70f
    Implements: blueprint add-scheduler-hints-step

commit edfb81d7cf3aa4ced14c831f7d09e97221a7a913
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Tue Jul 25 12:03:45 2017 +0900

    Add Security Groups steps into creation dialog
    
    To specify security groups options when create container,
    this patch adds Security Groups step into the creation dialog.
    
    The Security Groups step is not shown in update dialog.
    
    Also, security group infomations are shown in table view
    and details view.
    
    Change-Id: Ic67baa367eb1210dde8e6d7610fe2c5332631aa7
    Implements: bluepring add-security-groups

commit 8c9516a9a269a4184c6ec121fa92504e4ae84a6e
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Thu Jul 20 13:28:15 2017 +0000

    Updated from global requirements
    
    Change-Id: Ic0139eb4db8e17ae657ae59479bbbb13021e1d89

commit 7bee55d9258c67de922c656e2428522c6f9b36da
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Mon Jun 26 17:50:24 2017 +0900

    Enable to refresh details view
    
    For now refreshing details view by browser using F5 key or reload
    button, it causes 404 error from django. This patch fixes this issue.
    
    Change-Id: I3deb51a3895ad65be6e83dac61a4a5982ac21c45
    Closes-Bug: #1681627
    Depends-On: I4bcffd2e222ce2df186551cceba0aa38f600d9c8

commit a8e3b1988d8ae1e97aa3aa54ce5d5efd2a5f9105
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Thu Jul 13 15:16:01 2017 +0900

    Add configuration guide into docs
    
    This UI plugin has no specific configuration yet,
    so this patch adds only link to Horizon's guide.
    
    Also, fix title of linked documentation for contributor.
    
    Change-Id: I459e44c58f9ff15f81b9327505a22cfbf4653c0d

commit e04fd9f38027f36a3fe2d629c6799f97756d1d62
Merge: 54c1fad 496439b
Author: Jenkins <jenkins@review.openstack.org>
Date:   Thu Jul 13 06:04:15 2017 +0000

    Merge "Use pbr autodoc feature rather than custom logic"

commit 54c1fad7079c909a10e705631ffc0b339ce31dd4
Merge: 946490e 78d1a99
Author: Jenkins <jenkins@review.openstack.org>
Date:   Thu Jul 13 05:07:44 2017 +0000

    Merge "Imported Translations from Zanata"

commit 496439b2ade8ece4ecaa8b7bb370b8d4aa4e5b54
Author: Akihiro Motoki <amotoki@gmail.com>
Date:   Tue Jul 11 06:13:55 2017 +0000

    Use pbr autodoc feature rather than custom logic
    
    zun-ui doc/source/conf.py has a custom logic which prepare index files
    for autodoc, but now pbr and sphinx autodoc have a feature to do it and
    it is no a good idea to keep the custom logic.
    
    UI cookiecutter populates the custom logic and it is an example of
    the clean up.
    
    Change-Id: I6c6eb2f6292bda30a4fa8d4375defd8234463008

commit 78d1a990f61d6511c45b8fbb2c56a4739ac15e38
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Tue Jul 11 10:40:54 2017 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    http://docs.openstack.org/developer/i18n/reviewing-translation-import.html
    
    Change-Id: I7e12c482136889e2835281e2dcf212b6df505a13

commit 946490ea784028c2512fbcb8776f3c5354817942
Author: Akihiro Motoki <amotoki@gmail.com>
Date:   Mon Jul 10 14:59:46 2017 +0000

    rearrange existing documentation to fit the new standard layout
    
    For more detail, see the doc migration spec:
    http://specs.openstack.org/openstack/docs-specs/specs/pike/os-manuals-migration.html
    
    The current installation document is mainly for contributors not operators.
    It is better to be reviit later, but it is beyond the scope of this patch.
    
    Change-Id: Ibdbb20131b5c7bea6a1e6ab8ff47b971889ad319

commit ef783af9df516d4bbcc08741392ceb487cf70f2a
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Thu Jul 6 10:31:25 2017 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    http://docs.openstack.org/developer/i18n/reviewing-translation-import.html
    
    Change-Id: Ib35220fc986910a90d8dd45240fda6cd928a9ed0

commit 0cfafb4b36c9b681f0e8955d6ef9175fade0217c
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Thu Jul 6 01:47:44 2017 +0000

    Updated from global requirements
    
    Change-Id: Iadab251062f3527ae68a31981e7cffd525d6385a

commit b68516b9dea9629a188c8b4e839591e2c63fc1e0
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Wed Jun 28 17:50:24 2017 +0900

    Fix openstackdocstheme settings
    
    To use openstackdocstheme 1.11.0 properly, this patch fixes
    some settings according to follow.
    https://docs.openstack.org/openstackdocstheme/latest/
    
    Change-Id: If3f5c25611dffd462c8b8abe3ecc3f9aa00735ba

commit a7a9f208650ba7a1f6ab0bf57a8ba33c96fd286c
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Wed Jun 28 12:21:51 2017 +0900

    Switch from oslosphinx to openstackdocstheme
    
    As part of the docs migration work[0] for Pike we need to switch to use
    the openstackdocstheme.
    
    [0]https://review.openstack.org/#/c/472275/
    
    Change-Id: I5de43845fdd29a8fc6eddb6564c20da2a47c6581

commit 5699470a56780da15dc99118f3b58fbf57dceca5
Merge: bf6d4a8 164d295
Author: Jenkins <jenkins@review.openstack.org>
Date:   Wed Jun 28 02:54:38 2017 +0000

    Merge "Improve docs build"

commit bf6d4a865d5bc63d6330a2ece294dc07d2adcae8
Merge: 543d1d2 45c7633
Author: Jenkins <jenkins@review.openstack.org>
Date:   Wed Jun 28 02:54:32 2017 +0000

    Merge "Clean up doc/ and releasenotes/"

commit 543d1d2ce33349c3474bd04b1f9a2954a749d802
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Tue Jun 27 12:25:33 2017 +0000

    Updated from global requirements
    
    Change-Id: I63fad1010716a49b843e81865969916e547b79d5

commit 164d29526e047c7b9f8acd61e154b5e5d42ab3b2
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Tue Jun 27 17:17:17 2017 +0900

    Improve docs build
    
    Starting in Django 1.7, standalone scripts, such as a sphinx build
    require that django.setup() be called first. See:
    https://docs.djangoproject.com/en/1.8/releases/1.7/#standalone-scripts
    It does not always necessary, but it is needed to avoid warnings
    when creating autoindex.
    Note that horizon no longer generates the autoindex to avoid warnings.
    
    Drops setenv DJANGO_SETTINGS_MODULE in docs env in tox.ini.
    DJANGO_SETTINGS_MODULE is configured in doc/source/conf.py,
    so there is no need to pass envvar.
    
    Add warning-is-error sphinx setting to avoid doc build warnings.
    
    Change-Id: I4c036e264c7dd28463c3d52d73fcbbd3abeacb2b

commit 45c763336f13efec14ca0cbe3a1887266614c07a
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Tue Jun 27 16:29:35 2017 +0900

    Clean up doc/ and releasenotes/
    
    Already we setup reno environment. So there were two Release notes
    information: doc/source/releases and releasenotes (by reno).
    Release Notes in doc directory are unnecessary.
    
    It is not a good idea to have too much contents in the top page
    document. Installation stuff is split into a separate page.
    
    Title level of index.rst was inconsistent.
    
    _static and _templates directories in releasenotes/source
    are unnecessary. Also version info is set in release notes.
    
    Change-Id: I0c2c31c9efc71d97ccea064da36302d886d8a743

commit 9ac84cdc3673dc9ad6ab06c87fa6c211798e7cbe
Merge: 3c70594 051a02a
Author: Jenkins <jenkins@review.openstack.org>
Date:   Tue Jun 27 06:16:18 2017 +0000

    Merge "Fix image pull action"

commit 3c70594869f8dd23469acfa0d6df213f5bd13beb
Merge: 055f8f7 cb0a66c
Author: Jenkins <jenkins@review.openstack.org>
Date:   Tue Jun 27 02:41:29 2017 +0000

    Merge "Imported Translations from Zanata"

commit 051a02a67b6ff6ce2d82de4e3d52c053336f01cd
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Mon Jun 26 17:52:40 2017 +0900

    Fix image pull action
    
    For now pull image action doesn't work due to server error.
    The following patch adds second return value into
    _cleanup_params function, but the patch forgot to add the second
    return value for _cleanup_params in image_create function.
    https://review.openstack.org/#/c/474101/
    This patch fixes it.
    
    Change-Id: I5f2dca94821fa8c427e2804626f8b7f4a9fdcbb3
    Closes-Bug: #1700479

commit cb0a66c9db97052ada8b5c4838ad0eded0e7f95d
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Mon Jun 26 10:20:54 2017 +0000

    Imported Translations from Zanata
    
    For more information about this automatic import see:
    http://docs.openstack.org/developer/i18n/reviewing-translation-import.html
    
    Change-Id: Id619ed3d0d2feb8fefb0c6b5806a7a4a80883656

commit 055f8f71ea06ce2ca8df263f3969f9ed6526c198
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Mon Jun 26 11:38:25 2017 +0900

    Fix translate tag
    
    This patch fixes translation tag properly.
    
    Change-Id: Iecc6bd58d6bcc9e704d78358c03f5598d3d31517

commit bab87425d3c441958eba05187a72c9108b7fa92d
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Fri Jun 23 18:17:16 2017 +0000

    Updated from global requirements
    
    Change-Id: If510fad89e125175462d88fedf826df5664bda53

commit 6c41e2e2ade13c6337ebb319a751885cdc755bdd
Merge: 534d161 a13c830
Author: Jenkins <jenkins@review.openstack.org>
Date:   Fri Jun 23 01:07:17 2017 +0000

    Merge "hacking: Specify white list rules in noqa explicity"

commit 534d1615cbf94852b2ea5ce0de70db4dcd116e75
Merge: 7ddb9c6 0ad3744
Author: Jenkins <jenkins@review.openstack.org>
Date:   Thu Jun 22 10:52:47 2017 +0000

    Merge "Add reno for releasenotes management"

commit 0ad3744f640778e856f4f46b5732521faf47de9a
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Thu Jun 22 15:42:19 2017 +0900

    Add reno for releasenotes management
    
    An initial patch to add reno and create a base directory for
    release notes
    
    Change-Id: Ia8dbcf1aed76946a3f64c8d437f85ae88069db57

commit a13c830f1b2d2051b62eaf9857d4a2cbfdf2ee9a
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Thu Jun 22 12:02:53 2017 +0900

    hacking: Specify white list rules in noqa explicity
    
    If 'noqa' is specified all hacking checks are disabled.
    It is better to ignore specific rules explicitly rather than
    ignoring all. The recent flake8 supports this [1].
    
    [1] http://flake8.pycqa.org/en/stable/user/ignoring-errors.html
    
    Change-Id: I0f2a0cccf459c5a353f777a2be352c0faa8b18e0

commit 7ddb9c69add499bc8323b730d608f16044ea321d
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Thu Jun 22 12:35:03 2017 +0900

    ignore nose test results
    
    To exclude nose test results from git management,
    add '*nose_results.html' into .gitignore.
    
    Change-Id: I1675a795da350e862c2495b8a2ce8d7957f0d2db

commit 1efb2069dd488328ebc19379c787619889298cb1
Merge: aefbe4e fb51a6d
Author: Jenkins <jenkins@review.openstack.org>
Date:   Tue Jun 20 07:46:56 2017 +0000

    Merge "Use commonized serial console"

commit aefbe4e6f6dadf74363107d7d20a150e24a6e0df
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Mon Jun 19 14:47:39 2017 +0900

    Exclude node_modules directory from flake8 target
    
    Change-Id: I5927e3a5bdc6d4bd9e3f0649fa86a243d23c3178

commit fb51a6dcf657e582a80eb98cd687dc884387231f
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Thu Jun 15 18:20:16 2017 +0900

    Use commonized serial console
    
    This patch follows commonization of serial console in Horizon.
    
    Change-Id: I41f236f2762613e56748bb05eb7ce0e4c26158d2
    Depends-On: Ib0df9ddfc74f98bfea75abce3b5d5479e3cd47bd

commit ea685c4c92311d765115b926e56686fe8ea49e3e
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Wed Jun 14 18:11:22 2017 +0900

    Fix execute action
    
    For now, execute action doesn't works. This patch fixes it.
    
    Change-Id: If8dae8073ce832ba62de56c388480760375098dd

commit f42c24e1e8e8db5de67e05c6d466de6219b8b9e0
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Wed Jun 14 17:26:03 2017 +0900

    Enable to rename container in update action
    
    This patch enables to rename container in update action.
    
    Change-Id: I2c58d65355965f512ff89ba0b689d735b7f36522

commit 6ab8f75e592a060a6dddcad67e2ad995e3bd8bb1
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Wed Jun 14 16:20:45 2017 +0900

    Add update action for container
    
    This patch adds update action for container as item action.
    
    Change-Id: Ie80a1f447e218213adaff2253a1ec1afd7fe5672

commit 2fe0d6152958f1746f673273cd0be184169fe1af
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Wed Jun 14 13:38:53 2017 +0900

    Use Angular-Schema-Form for container creation
    
    To modify dialog easily, this patch uses Angular-Schema-Form
    for container creation dialog.
    This also makes easier to implement update dialog in the future.
    
    Change-Id: Id369ec6650931433e3e5fd4569838c3ff420e504

commit fa57cda20c265ea299a8d1f13121c4cf06553d29
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Tue Jun 13 18:58:21 2017 +0900

    Add parameters for cluster creation
    
    This patch adds 'image_driver', 'image_pull_policy' and
    'restart_policy' parameters into cluster creation action.
    
    Change-Id: I479e85787b0a2518968e8bb774159073b1573162

commit 68ceee59da5c554e7ed6b7adb9d5a526a798782b
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Sun Jun 4 03:03:59 2017 +0000

    Updated from global requirements
    
    Change-Id: Ie816a3fa508229e167a07a0c07da5d17b109bb83

commit 6d7a8dc3bfca7d4428d72be69bfc10fceb23b6f7
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Thu May 25 15:26:00 2017 +0900

    Add images panel into admin dashboard
    
    This patch adds images panel with pull action.
    
    To enable images panel, copy enabled files:
    * zun_ui/enabled/_2330_project_container_panelgroup.py
    * zun_ui/enabled/_2331_project_container_images_panel.py
    
    into horizon:
    * openstack_dashboard/local/enabled/
    
    Change-Id: I452449e6cf8dd5c150f5ff0843ce5babfface6ea
    Implements: blueprint add-images-panel

commit e9c497df6314f7c3cff82230d78188c03ae2db4b
Author: Hongbin Lu <hongbin.lu@huawei.com>
Date:   Fri May 19 00:40:09 2017 +0000

    Make console work with zun-wsproxy
    
    Zun server is switching to websockify library for streaming.
    This requires client to set sub-protocols manually.
    
    New WebSocket connection manner is completely same as of
    serial console for the instance.
    So it's enough to use django template for the instance.
    
    Change-Id: I7ebd0893ea4db0149fade4f32d6b70ee8b55147c

commit abe017df5971866259be9d0e38764e2cbd335301
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Wed May 17 04:01:09 2017 +0000

    Updated from global requirements
    
    Change-Id: I3beffd0e0ad2916aeb442e7b8fc2b30fad677eff

commit f02d6ddc4de7553208863cff2961b854789215de
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Mon May 15 00:57:48 2017 +0000

    Updated from global requirements
    
    Change-Id: If4c8fe7fb9b93ee0f7ec3fd3f23d160dc652b23f

commit cbd590935dcc8ce1896809bf7b83f21442b8e675
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Fri Apr 28 18:28:09 2017 +0900

    Bump 0.0.0 to 0.1.0
    
    Also, package.json needs to change its version.
    
    Change-Id: I4addcce29c8f4adcccfc1983c3cdcda8c622cfb9

commit 282c4f300c4543eaab73390ca4cf73fa4bd98409
Merge: eac8991 2a522be
Author: Jenkins <jenkins@review.openstack.org>
Date:   Mon Apr 24 18:56:46 2017 +0000

    Merge "Combine tty and stdin_open"

commit eac8991cc8b8ada06ad6ec6ba9fe0717e33c30e3
Merge: ef6732b d0df87d
Author: Jenkins <jenkins@review.openstack.org>
Date:   Mon Apr 24 06:34:21 2017 +0000

    Merge "Optimize the link address in README.rst"

commit ef6732bb8cc232030ef35208fb709846e5b9eec5
Merge: 04297f6 48c3414
Author: Jenkins <jenkins@review.openstack.org>
Date:   Fri Apr 21 13:13:07 2017 +0000

    Merge "Optimize the link address"

commit 2a522bec9fb76d877ce525f89bd5f58e9ffbd4d3
Author: Feng Shengqin <feng.shengqin@zte.com.cn>
Date:   Thu Apr 20 13:57:27 2017 +0800

    Combine tty and stdin_open
    
    Change-Id: I6b01c35260671ac0c45c5bb188aa07f637fb7eac
    Closes-Bug: #1683951

commit d0df87d19d4e82df2fa07e5b2124b8c3c54059f2
Author: Feng Shengqin <feng.shengqin@zte.com.cn>
Date:   Thu Apr 20 14:11:30 2017 +0800

    Optimize the link address in README.rst
    
    Use https instead of http in README.rst
    
    Change-Id: Ib35e2d45f7d49a0808b559de49bfdf3418d5b9fc

commit 48c34148be2e8587d5735bf433f698b53b002f56
Author: coldmoment <yan.zhiwei1@zte.com.cn>
Date:   Wed Apr 19 15:08:16 2017 +0800

    Optimize the link address
    
    Use https instead of http in installation guide
    
    Change-Id: I9099fd9067dc0f55bd071f7b397f88cc0b795c43

commit 04297f651ef56ea3a2da060840d51e3771bc0203
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Tue Apr 18 16:58:37 2017 +0000

    Updated from global requirements
    
    Change-Id: Iae0e790d3a7a27dbb1bda1c3c0849743568d4b55

commit 07866d2ca4bd729b530d1c04a00b850a425e62a4
Merge: ceebecb c8983de
Author: Jenkins <jenkins@review.openstack.org>
Date:   Mon Apr 17 08:12:31 2017 +0000

    Merge "Rename 'reboot' to 'restart'"

commit ceebecb9f3f6b0878502d5ca813a616373c58cf2
Merge: daa20b5 cbb5888
Author: Jenkins <jenkins@review.openstack.org>
Date:   Mon Apr 17 05:18:14 2017 +0000

    Merge "Refresh test environment"

commit cbb5888cffac6d376494d9f087e39394f2097a38
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Thu Apr 13 15:48:07 2017 +0900

    Refresh test environment
    
    To enable py35 tests, refresh test environments.
    Also, update docs, remove run_tests.sh that is no longer used.
    
    This patch needs to wait for adding python-zunclient into
    global-requirements.
    
    Change-Id: Ibed3eea72839226dca878d0ecd1778c9d9a7e7d3

commit c8983de01584743c26eb9b24a08b6986a657886e
Author: Hongbin Lu <hongbin.lu@huawei.com>
Date:   Fri Apr 14 23:58:00 2017 +0000

    Rename 'reboot' to 'restart'
    
    Change-Id: I5d821303f9e5efb80efeeb3b0d7b3c7c330fa13b
    Depends-On: I412fdb2123feb57b9fd5bcdb47ab389271d0d7e0
    Closes-Bug: #1682679

commit daa20b548381ebc9139f58a0357ed9c5287bb757
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Thu Apr 13 14:17:20 2017 +0900

    Handle 400/500 error on execute dialog
    
    If a 'exec' request returned 400/500, the UI doesn't handle it.
    This causes spinner remaining. This patch fixes the issue.
    Also, to ease to see status of exit code for command,
    change its container from readonly input text box to label.
    
    Change-Id: I833d5f448f5294ae8b537476e53643e35f25e7a2
    Closes-Bug: #1682173

commit 6644b6be772b3b6e4fa5659744fcc0cdb274a0a4
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Wed Apr 12 15:40:30 2017 +0900

    Increase the height of output area.
    
    It is better to increase the height of output area
    since the output couldn't fit into the box at majority cases.
    
    Change-Id: Ia8dbb2c3985eca7125575de803f7c5fa749558b2

commit cbdf73d63e2226c4fc65f3ce66839d41db39376f
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Wed Apr 12 04:24:32 2017 +0000

    Updated from global requirements
    
    Change-Id: Id534d8c41a9715f0524310ed7ddf8bf466711a82

commit 34c5b80f06796e4d823a8fc98a3ba64fdefa8722
Merge: 9d61096 526d442
Author: Jenkins <jenkins@review.openstack.org>
Date:   Wed Apr 12 01:23:08 2017 +0000

    Merge "Display output of command for execute action"

commit 526d4424a6a0a5f942fbd423d4c7ac0f5b9ddd8d
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Tue Apr 11 20:41:48 2017 +0900

    Display output of command for execute action
    
    This patch adds fields for output, exit code and message into Execute
    action dialog. To display output of command, this also modifies dialog
    not to be close by clicking submit button. To close this dialog, click
    cancel or type Esc key.
    
    Change-Id: I6f753387f4e8fa833b5081b4f11fa5c89927b6d0

commit 9d61096c2c4f845fd30f3cf660f7529e981ff533
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Tue Apr 11 12:42:38 2017 +0900

    Add dialogs for stop/reboot actions
    
    This patch adds dialogs for stop and reboot actions
    to specify timeout attribute.
    
    Change-Id: I4d7e92441dd976d6974c7b8ad84a5338b420c9d6

commit 5160eaddf4baa4b40136d726b66d2bace983f748
Merge: 75e5069 f8730d7
Author: Jenkins <jenkins@review.openstack.org>
Date:   Fri Apr 7 08:27:57 2017 +0000

    Merge "Don't get container's logs if it is creating"

commit 75e5069f32fb0b859cc252c9f377abca084ba739
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Fri Apr 7 06:19:02 2017 +0000

    Updated from global requirements
    
    Change-Id: Ic6b3377a13e3c95d9b6694df1c35829a8f08984b

commit f8730d79bd2e8a5cda74d19f291165720159c5ad
Author: Hongbin Lu <hongbin.lu@huawei.com>
Date:   Wed Apr 5 20:30:58 2017 +0000

    Don't get container's logs if it is creating
    
    Server might return a 400 error on getting logs on container with
    "Creating" state.
    
    Change-Id: I0bc16c15ca91698713a98368d3263ac8b8764536

commit 3ed91caa43721e90f989e829f398a12bf02207d1
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Wed Apr 5 15:09:34 2017 +0900

    Refresh views after actions
    
    This patch fixes to refresh views after actions,
    also adds refresh action as item action for manual refreshing.
    
    Adding refresh action is trivial fix. Ideally, refresh action
    should be implemented by Horizon framework.
    
    Change-Id: I1b0b5084a7a3a3df96e04200add8f3843587cb76

commit 2d1094c3639cfc0339e9cc30554fd395366e19f1
Merge: 328eca4 b2f0448
Author: Jenkins <jenkins@review.openstack.org>
Date:   Wed Apr 5 00:59:38 2017 +0000

    Merge "Fixed the error on stop reboot and kill"

commit b2f0448e57e34b12f290bced15cea9caa2e7aa75
Author: Hongbin Lu <hongbin.lu@huawei.com>
Date:   Mon Apr 3 19:56:21 2017 +0000

    Fixed the error on stop reboot and kill
    
    For stop and reboot, the timeout parameter is missing. For kill,
    it doesn't work if users left the signal unspecified.
    
    Change-Id: Ia1db001790fc491982ba4a6377bea2684d18f610

commit 328eca4a6892d9ce908cd108a0fba09a98e8f9f3
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Wed Mar 15 19:35:25 2017 +0900

    Add console tab into details view
    
    This patch adds console tab into details view. Console view
    gets console_url using attach method and access from browser
    via websocket using console_url.
    
    Change-Id: I273e83eb114e93371a23b9a1e9d26ceacb6b71d5
    Implements: blueprint interactive-mode

commit 5e68fcc08672e240526c95acb7ef10f23e61b986
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Tue Mar 28 15:42:21 2017 +0900

    Add 'interaction' attribute into creation dialog
    
    To enable Web console for container, this patch adds
    'interaction' attribute into creation dialog
    
    Change-Id: Ia941afad48c5f83594972f6f83d9267e36c04501
    Partial-Impements: blueprint interactive-mode

commit dc4ed360f86462332769401599209f60e009be02
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Tue Mar 28 15:27:24 2017 +0900

    Add 'run' attribute to create action
    
    To corresponse 'run' command of python-zunclient,
    this patch adds 'run' attribute to creation action.
    
    Change-Id: I80d478951c019284441093fa50f2d41bd970c473

commit f44f68aa9f6be43931a12ccd56514dd73ac96d75
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Tue Mar 21 15:34:09 2017 +0900

    Use detailRoute constant for path of details view
    
    This patch replaces hard coded "project/ngdetails/" for path of
    details view to constant using "horizon.app.core.detailRoute".
    
    Change-Id: Ia238f0a4b6df45f08673e4d41b24c6005d22ef00
    Closes-Bug: #1641250

commit c2042f873af204ae1deaabfa6d3341d8bfb71534
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Tue Mar 14 19:35:47 2017 +0900

    Fix eslint errors
    
    This patch fixes lint errors for JavaScript except "FIXME" warnings.
    
    Change-Id: Iefa0868365eb08c3a5383885dc1a747808751318
    Needed-By: Idb8b9064c1e465db8284e287bcf56949ab1de5e6

commit b56de185aa3fcf55fd461333ec1c6fe01bfbbf2d
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Tue Mar 14 18:34:00 2017 +0900

    Add Delete Container Force action
    
    This patch adds "Delete Container Forcely" action for each containers.
    This action is too dangerous for batch action, so implemented as only
    item action.
    
    Change-Id: Id839f2ce4beb17d7c4280cecf31b29e63f59197f

commit dbc4d9875214c84e282f714b2cf787ffdc2dfa1a
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Tue Mar 14 17:51:18 2017 +0900

    Revert APIs for images
    
    Incomplete implementation for image management are added.
    Also, adding APIs for image management is too early to implement.
    This patch revert it.
    
    Change-Id: I8dd0c25f62ecf3c606a893abdeded03e33f98949

commit e41f53d5bf78bd0e8afbb69a6a36324ee33a34cc
Merge: d614ccf 21f7908
Author: Jenkins <jenkins@review.openstack.org>
Date:   Sat Mar 11 10:56:06 2017 +0000

    Merge "Refresh table view and detail view"

commit d614ccff8785477d87e29e474be234c3cfab7d44
Merge: 0a375de 14f4bc1
Author: Jenkins <jenkins@review.openstack.org>
Date:   Sat Mar 11 10:54:55 2017 +0000

    Merge "Refresh js test environment"

commit 14f4bc1df1e35b95e3dc0db79c3f4f97859c4c2b
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Fri Mar 10 19:11:36 2017 +0900

    Refresh js test environment
    
    Before add CI jobs for JS tests, refresh test settings.
    
    Change-Id: Ic7d9314cf2381609fb584f8c97ddb201918e3061

commit 0a375deaa6f01fc45324bed8742f24defb909e65
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Fri Mar 10 18:05:57 2017 +0900

    Refactor zun.service.js
    
    There are many duplicated lines in zun.service.js.
    So this patch refactors this.
    
    convertMemorySize function is unnecessary,
    due to the memory size unit was fixed as MiB.
    Also, this patch removes it.
    
    Change-Id: I4e88e829eb3b2c7ea59b00381b9c7c873c8fe683

commit b359e776c1c73e32bbef2baff8f5dfc7a19ae17f
Merge: 49a2e90 4797b30
Author: Jenkins <jenkins@review.openstack.org>
Date:   Fri Mar 10 07:38:51 2017 +0000

    Merge "Hotfix creation dialog"

commit 21f79085d89520c6f8e44907c5d789d8829aa773
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Thu Mar 9 19:42:24 2017 +0900

    Refresh table view and detail view
    
    This patch refreshes columns for table view and
    properties for details view.
    Also, use hz-resource-property-list for them.
    
    Change-Id: I512de5bb76b1ea3d47ff4b5712bc9078e4f5e753

commit 49a2e90808db7ffb1cd71bf2cc78f80e7501d2f1
Merge: a4adc6d 95902b8
Author: Jenkins <jenkins@review.openstack.org>
Date:   Thu Mar 9 13:27:52 2017 +0000

    Merge "Fix get logs"

commit a4adc6db81839a8b91205b2dd2516e782ada912a
Merge: 184567c 7ab90cb
Author: Jenkins <jenkins@review.openstack.org>
Date:   Thu Mar 9 09:24:38 2017 +0000

    Merge "Update higgins with zun"

commit 4797b3027b041346955cf2c7a43bd180c07cfb53
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Thu Mar 9 17:20:18 2017 +0900

    Hotfix creation dialog
    
    This patch removes hostname and ports attributes, and modifies
    memory_size as MiB from create dialog.
    Also, merge environment tab into miscellaneous tab.
    
    Since create dialog will be changed widely in following patch,
    so this patch is provided as hotfix.
    
    Change-Id: I63920f7792655cce06d3bcf531ecdce6591cdd44

commit 95902b8a545849453124797eacd0dc3ff4aa5666
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Thu Mar 9 17:11:34 2017 +0900

    Fix get logs
    
    This patch fixes failure to get logs.
    
    Change-Id: I6cd7a8643d72a5620349751f090918bd5c01f56e

commit 7ab90cb9372e004eb76b636cf359a32544768e3f
Author: bhavani <bhavani.cr831@gmail.com>
Date:   Thu Mar 9 11:26:53 2017 +0530

    Update higgins with zun
    
    Updated the old name of higgins with new name zun.
    
    Change-Id: I3535a54bd3d77d9591d6f0dee8ad67acca89178a

commit 184567c9a06bdcd312721d1ac440bf4b73189069
Author: bhavani <bhavani.cr831@gmail.com>
Date:   Thu Mar 9 11:06:35 2017 +0530

    Remove Xstatic packages from requirements
    
    Following up the FFE request for xstatic packages [1].
    
    [1] http://lists.openstack.org/pipermail/openstack-dev/2017-February/111770.html
    
    Change-Id: I42480981b2245f18e425fed93cdbb79af59cf45d

commit bc0e54180d6db3524098653a0257e25200cb1c55
Author: OpenStack Proposal Bot <openstack-infra@lists.openstack.org>
Date:   Wed Mar 8 23:13:33 2017 +0000

    Updated from global requirements
    
    Change-Id: Ibcd11691227a3d4926bc580d473e64fb78c705e5

commit dbba806d00ff44706452c65212ea29bc3e74912b
Merge: 572c45b 5fdc2f7
Author: Jenkins <jenkins@review.openstack.org>
Date:   Thu Mar 2 10:56:01 2017 +0000

    Merge "changed the python version from 3.4 to 3.5 for better openstack support"

commit 572c45b07ac376d1d991872ebb9cab8cc1af3505
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Thu Mar 2 18:55:52 2017 +0900

    Update to a newer hacking library
    
    The older hacking library has a cap on pbr <2.0, with the recent 2.0.0
    release of PBR it's causing failures in the pep8 job. hacking isn't
    kept in sync via the typical proposal-bot updates. Do it manually to
    clear the gate issue.
    
    Change-Id: Iceb3aca107f067de568b26beacfccebe55c9e7bd
    Related-Bug: #1668848

commit 5fdc2f7bc4090e84a733dc9c08a4b938bf7fd8ba
Author: bhavani <bhavani.cr831@gmail.com>
Date:   Mon Feb 20 16:19:31 2017 +0530

    changed the python version from 3.4 to 3.5 for better openstack support
    
    Change-Id: I9eed250954075586b9e63943a10354bdffc45bd8

commit 2fd576b864c6c29d35212a4a581a4a1db1d2e34d
Merge: 503c16e 344aac0
Author: Jenkins <jenkins@review.openstack.org>
Date:   Mon Dec 26 10:47:50 2016 +0000

    Merge "Set reasonable name to browser title bar"

commit 503c16e050a5a123aaedda7103e128b1c328d6b6
Merge: 3841fe0 7e1829e
Author: Jenkins <jenkins@review.openstack.org>
Date:   Mon Dec 26 07:43:52 2016 +0000

    Merge "Add exec/kill action"

commit 344aac09aededa388458cb3a6a133de657f55861
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Mon Dec 26 13:37:39 2016 +0900

    Set reasonable name to browser title bar
    
    Currently, when using anuglar table, the name of title bar on
    browser is always "Horizon - OpenStack Dashboard".
    It's not good at point of view of usability.
    This patch fix it.
    
    Change-Id: I3e6e69f26d5d967bf402f8f5bc9f12d92c2edb87
    Closes-Bug: #1647855

commit 7e1829e4b622bfe74c090560330da7b8d6819f1f
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Wed Dec 21 20:07:44 2016 +0900

    Add exec/kill action
    
    This patch adds execute and kill action as item action
    in table view and details view.
    
    Change-Id: I782c893c3ad4847ac80b6e5282c2811f70e28929
    Partial-Implements: blueprint add-container-operations

commit 3841fe0cd8ea3ce8784662a72ca78bae468ba2e5
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Wed Dec 21 14:28:55 2016 +0900

    Use horizon's common "views" for Angular
    
    This patch replace views.py for each panel to the common views
    for Angularized panel in Horizon.
    
    Change-Id: Ib145b20e3399acb7445d55489abe3704e5742373

commit 299cc43c9848792eb3e23572188967fce2316b8f
Author: Kenji Ishii <ken-ishii@sx.jp.nec.com>
Date:   Fri Dec 2 11:04:52 2016 +0900

    Add mechanism to execute JavaScript test
    
    Same as other UI plugins, it can run tests by the following command.
    npm run test
    
    Change-Id: I5bf05b9b8b073b805844496a73670fd62c791160

commit 7edfcd5f0246653c074eec9ac14444dca398a36f
Merge: 677c031 cb3eb2e
Author: Jenkins <jenkins@review.openstack.org>
Date:   Fri Dec 2 15:54:23 2016 +0000

    Merge "Use initAction() instead initScope()"

commit cb3eb2e16b8bc8fa51bba532b1cb962771c72d74
Author: Kenji Ishii <ken-ishii@sx.jp.nec.com>
Date:   Fri Dec 2 10:57:16 2016 +0900

    Use initAction() instead initScope()
    
    initScope() for actions is deprecated in Ocata.[1]
    This patch use initAction() instead initScope().
    New scope is now provided as the second argument of perform().
    
    [1]:https://review.openstack.org/#/c/345145/
    
    Change-Id: Ie96f24fe7a892da29e4e2d80cfb100d2f3105c49

commit 677c03144edc3a0035e9ae336af0b2c1c6b50e2a
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Fri Dec 2 12:04:07 2016 +0900

    Cleanup .gitignore
    
    Add JS test environment, python develpment environment, transration
    and other development environments to .gitignore.
    
    Change-Id: I89a8b60cc8a7dc506317204da198cb7ac5e82735

commit de53f376541c45e2968514000bda6c263fdf9ac3
Merge: 09ed6a0 9d39165
Author: Jenkins <jenkins@review.openstack.org>
Date:   Wed Nov 2 05:53:21 2016 +0000

    Merge "Enable DeprecationWarning in test environments"

commit 09ed6a0608c9552de8af41748caf12ff1568436f
Author: nizam <abdul.nizamuddin@nectechnologies.in>
Date:   Fri Oct 28 19:31:17 2016 +0530

    Don't include openstack/common in flake8 exclude list
    
    The directory openstack/common was used to keep codes from
    oslo-incubator, we have retired oslo-incubator, so don't use
    this directory any more
    
    Change-Id: I7a1436c9dfb1b78b6c444c5701babf21b9895c40

commit 0340288589d697e5b02c51cd75bedce5ec0a4f14
Author: nizam <abdul.nizamuddin@nectechnologies.in>
Date:   Fri Oct 28 19:08:08 2016 +0530

    Drop MANIFEST.in - it's not needed by pbr
    
    zun-ui already uses PBR:-
    setuptools.setup(
        setup_requires=['pbr>=1.8'],
        pbr=True)
    
    This patch removes `MANIFEST.in` file as pbr generates a
    sensible manifest from git files and some standard files
    and it removes the need for an explicit `MANIFEST.in` file.
    
    Change-Id: I9a6fff81819e7a00e2928590acb4c7e6f3570df2

commit 9d39165266ba503bc35a186eaadd82ce74705d47
Author: Deepak <deepak.os31@yahoo.com>
Date:   Wed Oct 26 13:30:26 2016 +0530

    Enable DeprecationWarning in test environments
    
    Many deprecations are triggered early (on imports, for example).
    To make sure all DeprecationWarning messages are emitted we enable
    them via the PYTHONWARNINGS environment variable.
    
    Change-Id: I4a5d5d8278939e1faee7deef70f577c2a60b8a89

commit e9cc045221b937ad3ed6dd8062d5dcc844208e8a
Author: Deepak <deepak.os31@yahoo.com>
Date:   Fri Oct 21 18:18:24 2016 +0530

    Added releasenotes for Zun-UI
    
    Change-Id: Ib6b267cf040bba382be272916d53d146fd5c86e6
    Implements: blueprint need-releasenotes

commit 340c4d98be1da3ea999f262ba5507b5e75fda6ec
Merge: 45d81f4 57bdae4
Author: Jenkins <jenkins@review.openstack.org>
Date:   Thu Oct 13 14:21:46 2016 +0000

    Merge "Add container operations 'reboot', 'pause' and 'unpause'"

commit 45d81f4e33463e0aeda52edc6997dce26fd4b6b2
Merge: 78620be ca85c1d
Author: Jenkins <jenkins@review.openstack.org>
Date:   Thu Oct 13 14:14:35 2016 +0000

    Merge "Fix a duplicate request called when a user open a container panel"

commit 57bdae42d6619db5da3f35056338d45a6e26b7c6
Author: Kenji Ishii <ken-ishii@sx.jp.nec.com>
Date:   Tue Oct 11 15:51:31 2016 +0900

    Add container operations 'reboot', 'pause' and 'unpause'
    
    As a item action, this patch add three operations.
    'reboot', 'pause' and 'unpause'.
    
    Change-Id: I38534505568f4d363bc6e77cb8b5466292997d5f
    Partial-Implements: blueprint add-container-operations

commit ca85c1d979dcb3918f31cca4487686380b147c7a
Author: Kenji Ishii <ken-ishii@sx.jp.nec.com>
Date:   Tue Oct 11 16:12:39 2016 +0900

    Fix a duplicate request called when a user open a container panel
    
    Change-Id: Ide0010f1dc5d252767e172c5371d1d9b21b8216a
    Closes-Bug: #1632217

commit 78620bef275f9bad3faacef003fa826c4f53c95a
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Thu Oct 6 20:06:27 2016 +0900

    Add parameters for container
    
    This patch adds following parameters for container creation.
    
    * cpu
    * hostname
    * workdir
    * ports
    * labels
    
    Also, classify all params for creation dialog and details view.
    
    And 'task_state' is added for views.
    
    Change-Id: I647c8d6b06b9b573b45f804f55d4e2154e8c1f4a
    Depends-On: Ief55b52317c0a97dd7175556755e460522959789

commit c16e7a4b3d91924504b67dcdb52e49de25f73428
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Wed Oct 5 12:26:11 2016 +0900

    Add container operations
    
    This patch adds 'start', 'stop' and 'logs' operations
    for each container.
    
    'start' and 'stop' operations are added as item action
    in each row on table view and details view.
    'logs' are called while loading details view, then
    logs are shown in 'Logs' tab.
    
    Change-Id: I878728a2b05265d29a4d73918146083d90bec749
    Partial-Implements: blueprint add-container-operations

commit 543a2a02f447d8b0b525ad9247a502e92867b87d
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Tue Oct 4 16:16:49 2016 +0900

    Use zunclient instead of stub
    
    Use python-zunclient instead of stub client in skeleton.
    Then Zun-UI interacts with Zun API.
    
    This patch enable CRUD operation of containers.
    
    Change-Id: Idc869c0d4d40895e42ccf941f7fcb9d6d1dfb662
    Implements: blueprint use-zunclient

commit 325380b7b25d6b05a4ce910255f080e7170a4c20
Author: Sharat Sharma <sharat.sharma@nectechnologies.in>
Date:   Mon Oct 3 17:59:16 2016 +0530

    Changed the home-page of zun-ui
    
    Change-Id: I12adcbacc4fc144afe67d60beeb9cc97e27ce020

commit 6937c5e3b05d20fc51ee0020693117d7101ddc7b
Author: Kenji Ishii <ken-ishii@sx.jp.nec.com>
Date:   Fri Sep 9 10:06:03 2016 +0900

    Fix the path to an enabled folder in plugin.sh
    
    Change-Id: Ifd4f1d2883203dde2ebf2e5d2a05607567e9801b
    Closes-bug: #1621680

commit dc15e9d0d89449ca6ddc2421905f17f6a86afbc0
Author: Kenji Ishii <ken-ishii@sx.jp.nec.com>
Date:   Fri Sep 9 11:52:09 2016 +0900

    Fix pep8 errors
    
    Change-Id: I5f7ee36743f9476580dccf8f52aa097329316d67

commit 74342999eda05dc1b002935b3561455f1b0d9536
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Wed Sep 7 13:01:07 2016 +0900

    update test settings, cleanup REST api files

commit 73c2bcf7af6b45527f2940c57efc1f925d75b7cd
Author: Shu Muto <shu-mutou@rf.jp.nec.com>
Date:   Fri Jul 22 13:06:25 2016 +0900

    first commit
