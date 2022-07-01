* git pushを行ったところエラーになり、プッシュ出来なかった。
```
user@DESKTOP-M0KGDD4:~/project/WebApp$ git push -u origin main
Username for 'https://github.com': Ichikawa-Hisato
Password for 'https://Ichikawa-Hisato@github.com':
remote: Support for password authentication was removed on August 13, 2021. Please use a personal access token instead.
remote: Please see https://github.blog/2020-12-15-token-authentication-requirements-for-git-operations/ for more information.
fatal: Authentication failed for 'https://github.com/Ichikawa-Hisato/WebApp/'
```
* GitHubでhttpsのパスワード認証が廃止され、代わりにパーソナルアクセストークンを使うらしい。
    * https://qiita.com/shunsa10/items/e43564cf48f84b95455b