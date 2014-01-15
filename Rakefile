task :bump do
  version = get_version
  old_version = write_version(version)
  new_version = bump(version, "patch")
  file = File.open("CardFlight.podspec", "r")
  data = file.read
  new_data = data.gsub(old_version, new_version)
  file = File.open("CardFlight.podspec","w")
  file.write(new_data)
  file.close
  system 'git tag -a "#{new_version}" -m "bumping to version #{new_version}"'
  system 'git push --tags'
end


def get_version
  file = File.open("CardFlight.podspec", "r")
  data = file.read.split("\n")
  line = data[2]
  #return an array of version
  file.close
  return line[line.index("=")+3..line.size-2].to_s.split(".").map(&:to_i)
end

def write_version(a)
  a = a.map(&:to_s)
  "#{a[0]}.#{a[1]}.#{a[2]}"
end

def bump(a,type="minor")
  case(type)
  when "patch"
    a[2] = a[2]+1
  when "minor"
    a[1] = a[1]+1
  when "major"
    a[0] = a[0]+1

  end
  return write_version(a)
end
