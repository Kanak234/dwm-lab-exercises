import json, os
p = os.path.expanduser('~/.config/Code/User/settings.json')
os.makedirs(os.path.dirname(p), exist_ok=True)
s = open(p).read() if os.path.exists(p) else ''
if s.strip():
    open(p + '.bak', 'w').write(s)          # backup
try:
    d = json.loads(s) if s.strip() else {}
except Exception:
    d = {}                                   # had comments/was broken -> start fresh (backup kept)
d.setdefault('code-runner.executorMap', {}).update({
    'cpp': "cd $dir && g++ '$fileName' -o '$fileNameWithoutExt' -lGL -lGLU -lglut && '$dir$fileNameWithoutExt'",
    'c':   "cd $dir && gcc '$fileName' -o '$fileNameWithoutExt' -lGL -lGLU -lglut -lm && '$dir$fileNameWithoutExt'",
})
d['code-runner.runInTerminal'] = True
json.dump(d, open(p, 'w'), indent=4)
print('patched:', p)
